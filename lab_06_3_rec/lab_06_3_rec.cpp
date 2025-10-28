#include <iostream>
#include <string>
using namespace std;


int Min(int* a, const int size, int i);
template <typename T>
T Min(T* a, const int size, int i);

int main()
{
    const int n = 10;
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int m1 = Min(a, n, 0);
    cout << "Min(a, n) = " << m1 << endl;

    int m2 = Min<int>(a, n, 0);
    cout << "Min<int>(a, n) = " << m2 << endl;

    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    double m3 = Min<double>(b, n, 0);
    cout << "Min<double>(b, n) = " << m3 << endl;

    string c[n] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    string m4 = Min<string>(c, n, 0);
    cout << "Min<string>(c, n) = " << m4 << endl;

    return 0;
}


int Min(int* a, const int size, int i)
{
    if (i == size - 1)
        return a[i]; 

    int minRest = Min(a, size, i + 1);

    if (a[i] < minRest)
        return a[i];
    else
        return minRest;
}


template <typename T>
T Min(T* a, const int size, int i)
{
    if (i == size - 1)
        return a[i]; 

    T minRest = Min<T>(a, size, i + 1); 

    if (a[i] < minRest)
        return a[i];
    else
        return minRest;
}
