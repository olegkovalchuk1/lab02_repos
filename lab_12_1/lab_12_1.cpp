#include <iostream>
#include <string>
#include "FileOps.h" // Підключаємо наш модуль

using namespace std;

int main() {
    // Введення імен файлів з клавіатури (використовуємо string для зручності вводу, 
    // але передаємо у функції c_str(), щоб відповідати сигнатурі const char*)
    string sourceFileName;
    string evenFileName;
    string oddFileName;

    cout << "Enter source filename (e.g., data.bin): ";
    cin >> sourceFileName;

    cout << "Enter filename for EVEN numbers (e.g., even.bin): ";
    cin >> evenFileName;

    cout << "Enter filename for ODD numbers (e.g., odd.bin): ";
    cin >> oddFileName;
    cout << "------------------------------------------------" << endl;

    // 1. Формування файлу даних
    cout << "Step 1: Creating source file." << endl;
    CreateFile(sourceFileName.c_str());

    // 2. Виведення початкового файлу (для перевірки)
    cout << "Source file content: ";
    PrintFile(sourceFileName.c_str());
    cout << "------------------------------------------------" << endl;

    // 3. Опрацювання даних (розділення)
    // Функція нічого не виводить, лише працює з файлами
    SplitFile(sourceFileName.c_str(), evenFileName.c_str(), oddFileName.c_str());
    cout << "Step 2: Data processed and split." << endl;
    cout << "------------------------------------------------" << endl;

    // 4. Вивід результатів
    cout << "Content of EVEN numbers file: ";
    PrintFile(evenFileName.c_str());

    cout << "Content of ODD numbers file: ";
    PrintFile(oddFileName.c_str());

    return 0;
}