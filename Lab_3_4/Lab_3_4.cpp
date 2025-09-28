// Lab_03_4.cpp
// <прізвище, ім’я автора>
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 10

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x; // вхідний аргумент
    double y; // вхідний параметр
    double R, a, b; // параметри

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "R = "; cin >> R;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    // розгалуження в повній формі
    if (((x * x + y * y <= R * R) && (x <= 0) && (y <= 0)) ||
        ((x * x + y * y >= R * R) && (x >= 0) && (x <= a) && (y >= 0) && (y <= b)))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
