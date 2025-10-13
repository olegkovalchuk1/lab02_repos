// Lab 5_1
#include <iostream>
#include <cmath>
using namespace std;

double f(const double a, const double b, const double c); // прототип

int main()
{
    double s, t;
    cout << "s = "; cin >> s;
    cout << "t = "; cin >> t;

    double c = (f(t, s, 2) + f(1, s + t, t - s))/(1 + f(1, 1, t * t + s * s) * f(1, 1, t * t + s * s));
    

    cout << "result = " << c << endl;
    return 0;
}

double f(const double a, const double b, const double c) // визначення
{
    return (a + b + c) / (sin(a * b) * sin(a * b) + c * c);
}
