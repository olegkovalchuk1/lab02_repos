#include <iostream>
#include <cmath>
using namespace std;

int Level = 0;   
int Depth = 0;       
double power(double x, int n) {
   
    Level++;
    if (Level > Depth)
        Depth = Level;

    double result;
    if (n == 0)
        result = 1;
    else if (n < 0)
        result = 1 / power(x, abs(n));
    else
        result = x * power(x, n - 1);

    cout << "Level of recursion: " << Level << endl;
    Level--;
    return result;
}

int main() {
   

    double x;
    int n;

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;

    double result = power(x, n);

    cout << "Result: " << result << endl;
    cout << "Depth of recursion: " << Depth << endl;

    return 0;
}
