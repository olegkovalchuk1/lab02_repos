// Lab_03_1.cpp
// Ковальчук Олег
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 10

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;  // вхідний параметр
    double y;  // результат обчислення виразу
    double A;  // функціонально стала частина виразу
    double B;  // функціонально змінна частина виразу

    cout << "x = ";
    cin >> x;

    A = 4.95 * x * x;

    // спосіб 1: скорочена форма
    if (x < -3.5)
        B = 4 + pow(x, -2);
    if (x >= -3.5 && x < 1)
        B = tan((3.5 + x) / 5.0);
    if (x >= 1)
        B = sin(3 * x) - cos(x);

    y = A + B;

    cout << endl;
    cout << "1) y = " << y << endl;

    // спосіб 2: повна форма
    if (x < -3.5)
        B = 4 + pow(x, -2);
    else if (x < 1)
        B = tan((3.5 + x) / 5.0);
    else
        B = sin(3 * x) - cos(x);

    y = A + B;

    cout << "2) y = " << y << endl;

    cin.get(); 
    
    return 0;
}
