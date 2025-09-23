// Lab_02.cpp 
// Ковальчук Олег
// Лабораторна робота № 2.1 
// Лінійні програми. 
// Варіант 10

#include <iostream> 
#include <cmath> 

using namespace std;

int main() {
	double Pi = 4 * atan(1.); // число пі 
	double alpha;  // вхідний параметр 
	double z1; // результат обчислення 1-го виразу 
	double z2; // результат обчислення 2-го виразу

	cout << "alpha = ";
	cin >> alpha;

	z1 = sin(Pi / 2 + 3 * alpha) / (1 - sin(3 * alpha - Pi));
	z2 = 1.0 / tan((5.0 / 4.0) * Pi + (3.0 / 2.0) * alpha);

	cout << endl;
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	cin.get();

	return 0;
}

