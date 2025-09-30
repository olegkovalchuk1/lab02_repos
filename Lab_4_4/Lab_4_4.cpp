// Lab_04_4.cpp
// Ковальчук Олег
// Лабораторна робота №4.3
//Табуляція функції, заданої графічно
// Варіант 10 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double R, x, xp, xk, dx, y;

    cout << "R = "; cin >> R;
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
        if (x <= -8 - R)
            y = R;
        else if (x > -8 - R && x <= -8)
            y = R - sqrt(R * R - (x + 8) * (x + 8));
        else if (x > -8 && x <= -8 + R)
            y = sqrt(R * R - (x + 8) * (x + 8));
        else if (x > -8 + R && x <= -4)
            y = R;
        else if (x > -4 && x <= 0)
            y = -(R / 4.0) * x;
        else if (x > 0 && x <= 2)
            y = -0.5 * x;
        else if (x > 2 && x <= 3)
            y = x - 3;
        else
            y = x - 3;

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(12) << setprecision(5) << y
            << " |" << endl;

        x += dx;
    }

    cout << "---------------------------------" << endl;
    return 0;
}
