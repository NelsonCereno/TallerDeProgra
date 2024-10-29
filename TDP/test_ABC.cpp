#include "C.h"
#include "B.h"

int main() {
    // aqui construyen su repositorio de operaciones
    // esto iria en el constructor de Jug
    A **o = new A* [4];
    o[0] = new B(1,2);
    o[1] = new B(3,4);
    o[2] = new C(1);
    o[3] = new C(2);


    // aqui llamamos genericamente a cada operacion, es automatico
    for (int k=0; k<4; k++) {
        cout << "k:" << k << " operate:" << o[k]->operate(k) << endl;
    }


}