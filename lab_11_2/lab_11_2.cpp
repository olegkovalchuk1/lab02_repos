#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "file_utils.h" 

using namespace std;

int main()
{
    char fname[100];

    cout << "Enter the name of existing file (e.g., t.txt): ";
    cin >> fname;

    // 1. Спочатку просто виводимо текст, щоб переконатися, що файл знайшовся
    PrintTXT(fname);

    // 2. Викликаємо функцію пошуку
    bool result = ContainsWordStartingWithA(fname);

    // 3. Обробляємо результат, який повернула функція
    if (result)
    {
        cout << "Yes, the file contains a word starting with 'a'." << endl;
    }
    else
    {
        cout << "No, there are no words starting with 'a' (or file not found)." << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}