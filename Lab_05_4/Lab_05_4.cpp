// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;

double S0(const int N)
{
    double s = 1;
    for (int i = N; i <= 16; i++)
        s *= (1.0 * i * N) / (i * i + N * N);
    return s;
}

double S1(const int N, const int i)
{
    if (i > 16)
        return 1;
    else
        return (1.0 * i * N) / (i * i + N * N) * S1(N, i + 1);
}

double S2(const int N, const int i)
{
    if (i < N)
        return 1;
    else
        return (1.0 * i * N) / (i * i + N * N) * S2(N, i - 1);
}

double S3(const int N, const int i, double t)
{
    t = t * (1.0 * i * N) / (i * i + N * N);
    if (i >= 16)
        return t;
    else
        return S3(N, i + 1, t);
}

double S4(const int N, const int i, double t)
{
    t = t * (1.0 * i * N) / (i * i + N * N);
    if (i <= N)
        return t;
    else
        return S4(N, i - 1, t);
}

int main()
{
    int N;
    cout << "N = ";
    cin >> N;

    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec up ++) S1 = " << S1(N, N) << endl;
    cout << "(rec up --) S2 = " << S2(N, 16) << endl;
    cout << "(rec down ++) S3 = " << S3(N, N, 1) << endl;
    cout << "(rec down --) S4 = " << S4(N, 16, 1) << endl;

    return 0;
}
