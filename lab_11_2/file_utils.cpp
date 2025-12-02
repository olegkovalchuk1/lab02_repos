#define _CRT_SECURE_NO_WARNINGS
#include "file_utils.h"

void PrintTXT(char* fname)
{
    ifstream fin(fname);
    // ѕерев≥рка, чи файл взагал≥ ≥снуЇ
    if (!fin.is_open())
    {
        cout << "Error: File '" << fname << "' not found." << endl;
        return;
    }

    string s;
    cout << "\n--- File Content Start ---" << endl;
    while (getline(fin, s))
    {
        cout << s << endl;
    }
    cout << "--- File Content End ---\n" << endl;
    fin.close();
}

bool ContainsWordStartingWithA(char* fname)
{
    ifstream fin(fname);
    if (!fin.is_open())
    {
        return false; // якщо файлу немаЇ, то ≥ сл≥в немаЇ
    }

    string word;
    // „итаЇмо файл по словах (проб≥ли та ентери пропускаютьс€ автоматично)
    while (fin >> word)
    {
        // ѕерев≥р€Їмо першу л≥теру (враховуЇмо лише малу 'a')
        if (word.length() > 0 && word[0] == 'a')
        {
            fin.close();
            return true;
        }
    }

    fin.close();
    return false;
}