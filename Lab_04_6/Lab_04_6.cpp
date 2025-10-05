#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S;   
    double P;   
    int n, k;

    // 1) while … while …
    S = 0;
    n = 1;
    while (n <= 10) {
        P = 1;
        k = 1;
        while (k <= n) {
            P *= sin(k + n);
            k++;
        }
        S += sqrt(1 + cos(n) * cos(n) + P);
        n++;
    }
    cout << "while-while: " << S << endl;

    // 2) do … do …
    S = 0;
    n = 1;
    do {
        P = 1;
        k = 1;
        do {
            P *= sin(k + n);
            k++;
        } while (k <= n);
        S += sqrt(1 + cos(n) * cos(n) + P);
        n++;
    } while (n <= 10);
    cout << "do-do: " << S << endl;

    // 3) for n++ … for k++
    S = 0;
    for (n = 1; n <= 10; n++) {
        P = 1;
        for (k = 1; k <= n; k++) {
            P *= sin(k + n);
        }
        S += sqrt(1 + cos(n) * cos(n) + P);
    }
    cout << "for++: " << S << endl;

    // 4) for n-- … for k--
    S = 0;
    for (n = 10; n >= 1; n--) {
        P = 1;
        for (k = n; k >= 1; k--) {
            P *= sin(k + n);
        }
        S += sqrt(1 + cos(n) * cos(n) + P);
    }
    cout << "for--: " << S << endl;

    return 0;
}
