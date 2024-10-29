#include "C.h"

C::C(int a) {
    this->a=10*a;
}
int C::operate(int x) {
    return(3*x+a);
}

