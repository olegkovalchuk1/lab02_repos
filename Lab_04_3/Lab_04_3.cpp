// Lab_04_3.cpp
// Ковальчук Олег
// Лабораторна робота №4.3
/*Табуляція функції, заданої
формулою: функція з параметрами*/
// Варіант 10

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;
    double a, b, c;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "y" << " |" << endl;
    cout << "---------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x < 3 && b != 0)
            y = a * x * x - b * x + c;
        else if (x > 3 && b == 0 && x != c)
            y = (x - a) / (x - c);
        else if (c != 0)
            y = x / c;
        else {
            cout << "|" << setw(7) << setprecision(2) << x
                << " |" << setw(12) << "невизначено" << " |" << endl;
            x += dx;
            continue;
        }

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(12) << setprecision(5) << y
            << " |" << endl;

        x += dx;
    }

    cout << "---------------------------------" << endl;
    return 0;
}
