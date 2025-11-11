#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


int Count(char* str, int i)
{
    if (strlen(str) < 2) // рядок менший за 2 символи
        return 0;

    if (str[i + 1] != 0)
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
            return 1 + Count(str, i + 1); 
        else
            return Count(str, i + 1);
    }
    else
        return 0;
}


char* Change(char* dest, const char* str, char* t, int i)
{
#pragma warning(disable : 4996)

    size_t len = strlen(str);

    if (i < len - 1) // поки є ще пара символів
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
        {
            strcat(t, "***");             // додаємо зірочки
            return Change(dest, str, t + 3, i + 2); // пропускаємо обидва символи пари
        }
        else
        {
            *t++ = str[i++];              // копіюємо символи, які не замінюються
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else if (i < len) // якщо залишився останній символ
    {
        *t++ = str[i++];
        *t = '\0';
    }

    return dest;
}

int main()
{
    char str[101];      // вхідний рядок
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Підрахунок перетинаючих пар
    int pairs = Count(str, 0);
    cout << "String contained " << pairs << " pairs of 'aa', 'bb', or 'cc'" << endl;

    // Заміна пар на ***
    char* dest1 = new char[201]; // буфер для нового рядка
    dest1[0] = '\0';
    char* dest2 = Change(dest1, str, dest1, 0);

    // Вивід
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    return 0;
}
