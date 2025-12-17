#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    char fname[100]; // масив символів для імені файлу
    int item; // вибір пункту меню

    cout << "Enter file name: "; cin >> fname;

    do {
        cout << endl << "MENU:" << endl;
        cout << "1 - Create file" << endl;
        cout << "2 - Print table" << endl;
        cout << "3 - Count 'Good' marks" << endl;
        cout << "4 - Percent 'Excellent'" << endl;
        cout << "0 - Exit" << endl;
        cout << "Select: "; cin >> item;

        switch (item)
        {
        case 1:
            Create(fname); // створення
            break;
        case 2:
            Print(fname); // вивід таблиці
            break;
        case 3:
        {
            ResultCounts r = CalcGood(fname); // викликаємо функцію
            // виводимо результат, який вона повернула
            cout << "Count of '4' (Good):" << endl;
            cout << "Physics: " << r.cntPhys << endl;
            cout << "Math:    " << r.cntMath << endl;
            cout << "CS:      " << r.cntInf << endl;
        }
        break;
        case 4:
        {
            double p = CalcPercent(fname); // викликаємо функцію
            cout << "Students with '5' in Phys & Math: " << p << "%" << endl;
        }
        break;
        case 0:
            break;
        default:
            cout << "Error choice!" << endl;
        }
    } while (item != 0);

    return 0;
}