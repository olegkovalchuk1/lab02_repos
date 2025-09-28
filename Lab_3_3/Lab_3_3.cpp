// Lab_03_3.cpp
// Ковальчук Олег
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 10

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, R, y;

    cout << "R = "; cin >> R;
    cout << "x = "; cin >> x;

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

    cout << "y = " << y << endl;

    return 0;
}
