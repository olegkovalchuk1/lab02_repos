///////////////////////////////////////////////
// sum.cpp
#include <math.h>
#include "dod.h"
#include "sum.h"
#include "var.h"
using namespace nsDod;
using namespace nsVar;
void nsSum::sum(){
    n = 0;
    a = x;   // first term = x^(2*0+1) / (2*0+1) = x
    s = a;

    do{
        n++;
        dod();
        s += a;
    } while (fabs(a) > e);
}