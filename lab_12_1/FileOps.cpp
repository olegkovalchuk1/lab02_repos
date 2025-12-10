#include "FileOps.h"

// Створення файлу цілих чисел
void CreateFile(const char* fileName)
{
    ofstream fout(fileName, ios::binary); // Відкриваємо для запису в бінарному режимі
    if (!fout) {
        cerr << "Error opening file for writing: " << fileName << endl;
        return;
    }

    char ch;
    int num;

    do {
        cout << "Enter integer number: ";
        cin >> num;

        // Записуємо число (int) у бінарному форматі
        fout.write((char*)&num, sizeof(int));

        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fout.close();
    cout << endl;
}

// Виведення файлу на екран
void PrintFile(const char* fileName)
{
    ifstream fin(fileName, ios::binary); // Відкриваємо для читання
    if (!fin) {
        cerr << "Error opening file for reading: " << fileName << endl;
        return;
    }

    int num;
    // Читаємо по одному числу, поки читається
    while (fin.read((char*)&num, sizeof(int))) {
        cout << num << " ";
    }
    cout << endl;
    fin.close();
}

// Опрацювання: поділ на парні та непарні
void SplitFile(const char* sourceName, const char* evenName, const char* oddName)
{
    ifstream fin(sourceName, ios::binary);
    ofstream feven(evenName, ios::binary);
    ofstream fodd(oddName, ios::binary);

    if (!fin || !feven || !fodd) {
        cerr << "Error opening files!" << endl;
        return;
    }

    int num;
    // Цикл зчитування по одному числу (без масивів)
    while (fin.read((char*)&num, sizeof(int))) {
        if (num % 2 == 0) {
            // Запис у файл парних
            feven.write((char*)&num, sizeof(int));
        }
        else {
            // Запис у файл непарних
            fodd.write((char*)&num, sizeof(int));
        }
    }

    fin.close();
    feven.close();
    fodd.close();
}