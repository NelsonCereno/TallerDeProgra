// se incluyen todas las librerias necesarias
#include <iostream>
#include <string>

using namespace std;

// Se define el estado para el problema de los bidones
class State {
    public:
    int a0;
    int a1;
    State *parent;
    string operation;
    State(int a0, int a1, State *parent, string operation);
    void print(); // imprime el estado y toda la secuencia de operaciones que lo generaron
};