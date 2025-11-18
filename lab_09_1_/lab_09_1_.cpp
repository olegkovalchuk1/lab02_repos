///////////////////////////////////////////////
// Lab_9_1.cpp
#include <iostream>
#include <math.h>
#include <iomanip>
#include "dod.h"
#include "sum.h"
#include "var.h"
using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;
int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx = "; cin >> dx;
    cout << "e = "; cin >> e;
    cout << endl;

    
    cout << "-----------------------------------------------------------------" << endl;

    
    cout << "| " << left << setw(8) << "x"
        << " | " << setw(18) << "Sum"
        << " | " << setw(18) << "atanh(x)"
        << " | " << setw(8) << "n" << " |" << endl;

    
    cout << "-----------------------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) {  
        sum();

        cout << "| " << left << setw(8) << x
            << " | " << setw(18) << s
            << " | " << setw(18) << (0.5 * log((1 + x) / (1 - x)))
            << " | " << setw(8) << n << " |" << endl;

        x += dx;
    }

    
    cout << "-----------------------------------------------------------------" << endl;

    cin.get();
    return 0;
}


