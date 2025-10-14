#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double y(const double x);

int main()
{
    double fp, fk;
    int n;
    cout << "fp = "; cin >> fp;
    cout << "fk = "; cin >> fk;
    cout << "n = "; cin >> n;

    double df = (fk - fp) / n;
    double f = fp;

    cout << "----------------------------------------" << endl;
    cout << "|" << setw(10) << "f"
        << " |" << setw(25) << "y(f/2) + y^2(f+1) + y(2f)" << " |" << endl;
    cout << "----------------------------------------" << endl;

    while (f <= fk) 
    {
        double z = y(f / 2) + pow(y(f + 1), 2) + y(2 * f);
        cout << "|" << setw(10) << fixed << setprecision(5) << f
            << " |" << setw(25) << fixed << setprecision(10) << z << " |" << endl;
        f += df;
    }

    cout << "----------------------------------------" << endl;
    return 0;
}

double y(const double x)
{
    if (abs(x) >= 1)
        return exp(x) / (1 + exp(x) + sin(x));
    else
    {
        double S = 1;
        double a = 1; // перший доданок
        int j = 1;
        do
        {
            double R = (-1) * x * x / ((2 * j) * (2 * j - 1)); // рекурентне співвідношення
            a *= R;
            S += a;
            j++;
        } while (j <= 8);
        return S;
    }
}
