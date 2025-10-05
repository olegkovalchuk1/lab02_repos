#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	double x, y;
	double R, a, b;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;
		cout << "R = "; cin >> R;
		cout << "a = "; cin >> a;
		cout << "b = "; cin >> b;

		if   (((0 <= x) && (x <= a) && (0 <= y) && (y <= b) && ((x * x + y * y) >= (R * R)))
				|| ((-a <= x) && (x <= 0) && (-b <= y) && (y <= 0) && ((x * x + y * y) <= (R * R))))

			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	cout << endl << fixed;

for (int i = 0; i < 10; i++)
	{
	    x = -(max({ a,b,R })) + (2.0 * max({ a,b,R }) * rand()) / RAND_MAX;
		y = -(max({ a,b,R })) + (2.0 * max({ a,b,R }) * rand()) / RAND_MAX;

		if (((0 <= x) && (x <= a) && (0 <= y) && (y <= b) && ((x * x + y * y) >= (R * R)))
			|| ((-a <= x) && (x <= 0) && (-b <= y) && (y <= 0) && ((x * x + y * y) <= (R * R))))

			cout << setw(8) << setprecision(4) << x << " "
			<< setw(8) << setprecision(4) << y << " " << "yes" << endl;
		else
			cout << setw(8) << setprecision(4) << x << " "
			<< setw(8) << setprecision(4) << y << " " << "no" << endl;
	}
	return 0;
}
