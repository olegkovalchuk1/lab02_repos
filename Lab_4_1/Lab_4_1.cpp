#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "N = ";
    cin >> N;

   
        double P;
    int i;

    // 1) while
    P = 1.0;
    i = N;
    while (i <= 16) {
        P *= (1.0 * i * N) / (i * i + N * N);
        i++;
    }
    cout << "while: " << P << endl;

    // 2) do...while
    P = 1.0;
    i = N;
    if (N <= 16) {
        do {
            P *= (1.0 * i * N) / (i * i + N * N);
            i++;
        } while (i <= 16);
    }
    cout << "do...while: " << P << endl;

    // 3) for (з наростанням)
    P = 1.0;
    for (i = N; i <= 16; i++) {
        P *= (1.0 * i * N) / (i * i + N * N);
    }
    cout << "for++: " << P << endl;

    // 4) for (зі спаданням)
    P = 1.0;
    for (i = 16; i >= N; i--) {
        P *= (1.0 * i * N) / (i * i + N * N);
    }
    cout << "for--: " << P << endl;

    return 0;
   

}
