#include "A.h"

A::A() {
    a=0;
}
#include "C.h"
#include "B.h"
A::A(int a) {
    this->a = a;
}

int A::operate(int b) {
    return a + b;
}

