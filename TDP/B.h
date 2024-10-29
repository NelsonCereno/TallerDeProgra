#include "A.h"

// B hereda de A de forma publica
// esto significa que los miembros publicos de A
// seran publicos en B
class B : public A {
    public:
    int b;
    B(int a, int b);
    void print();
    int operate(int b);
};