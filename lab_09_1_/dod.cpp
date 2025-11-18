///////////////////////////////////////////////
// dod.cpp
#include "dod.h"
#include "var.h"
using namespace nsVar;
void nsDod::dod(){
    // recurrence for x^(2n+1)/(2n+1)
    // a(n+1) = a(n) * x*x * (2n-1)/(2n+1)
    a *= x * x * ((2.0 * n - 1) / (2.0 * n + 1));
}