#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* str)
{
    if (strlen(str) < 2)
        return 0;
    int k = 0;
    for (int i = 0; str[i + 1] != 0; i++)
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
            k++;
    return k;
}


char* Change(char* str)
{
#pragma warning(disable : 4996)

    size_t len = strlen(str);
    if (len < 2)
        return str;
    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len && str[i + 1] != 0)
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    if (i < len)
    {
        *t++ = str[i++];
        *t = '\0';
    }

    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " pairs of 'aa', 'bb', or 'cc'" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
