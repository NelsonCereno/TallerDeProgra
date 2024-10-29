#include "B.h"

B::B(int a,int b) { // se necesita un constructor A() porque 
                    // porque antes de ejecutar este constructor 
                    // se llama a A(int,int) si existe y sino llama a A()
    this->a=a ;
    this->b=b; 
}

void B::print() {
    cout << "a:" << a << " b:" << b << endl;
}

int B::operate(int x) {
    return x*a+b;
}
