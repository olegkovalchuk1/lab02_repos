// Lab_03_4.cpp
// <�������, ��� ������>
// ����������� ������ � 3.4
// ������������, ������ ������� �������.
// ������ 10

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x; // ������� ��������
    double y; // ������� ��������
    double R, a, b; // ���������

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "R = "; cin >> R;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    // ������������ � ����� ����
    if (((x * x + y * y <= R * R) && (x <= 0) && (y <= 0)) ||
        ((x * x + y * y >= R * R) && (x >= 0) && (x <= a) && (y >= 0) && (y <= b)))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
