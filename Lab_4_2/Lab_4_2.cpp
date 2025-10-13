// Lab_04_2.cpp
// Ковальчук Олег
// Лабораторна робота №4.2
/*Табуляція функції, заданої
формулою: функція однієї змінної*/
//формулою: функція однієї змінної
// Варіант 10

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "y" << " |" << endl;
    cout << "------------------------" << endl;

    x = xp;
    while (x <= xk )  
    {
        A = 4.95 * x * x;

        if (x < -3.5)
            B = 4 + pow(x, -2);
        else if (x < 1)
            B = tan((3.5 + x) / 5.0);
        else
            B = sin(3 * x) - cos(x);

        y = A + B;

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(12) << setprecision(5) << y
            << " |" << endl;

        x += dx;
    }

    cout << "------------------------" << endl;
    return 0;
}
