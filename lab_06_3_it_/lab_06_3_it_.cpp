#include <iostream>
#include <string>
using namespace std;


int Min(int* a, const int size);


template <typename T>
T Min(T* a, const int size);

int main()
{
    const int n = 10;
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int m1 = Min(a, n);
    cout << "Min(a, n) = " << m1 << endl;
    int m2 = Min<int>(a, n);
    cout << "Min<int>(a, n) = " << m2 << endl;

    double b[n] = { 1.1, 2.2, 3.3, 4.3, 5.5, 6.6, 7.7, 8.8, 9.9, 0.1 };
    double m3 = Min<double>(b, n);
    cout << "Min<double>(b, n) = " << m3 << endl;

    string c[n] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    string m4 = Min<string>(c, n);
    cout << "Min<string>(c, n) = " << m4 << endl;

    return 0;
}


int Min(int* a, const int size)
{
    int m = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < m)
            m = a[i];
    return m;
}


template <typename T>
T Min(T* a, const int size)
{
    T m = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < m)
            m = a[i];
    return m;
}
