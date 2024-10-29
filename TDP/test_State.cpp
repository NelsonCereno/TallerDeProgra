#include "State.h"

int main() {
    State *s = new State(0, 0, nullptr, "init");
    State *s1 = new State(3, 0, s, "fill a0");
    State *s2 = new State(3, 5, s1, "fill a1");
    State *s3 = new State(0, 5, s2, "pour a0");
    s3->print();

    int *x = new int[5]; // esto crea un arreglo de 5 enteros

    return 0;
}