#ifndef A_CLASS
#define A_CLASS


#include <iostream>

using namespace std;

class A {
    public:
    int a;
    A(); // ya que A es madre entonces requiere al menos un constructor por defecto
    A(int a);
    int virtual operate(int b); // virtual indica que se puede sobreescribir este metodo
                                // se implementa como una tabla de punteros 
};

#endif
