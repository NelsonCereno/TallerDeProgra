// este un archivo de implementacion de la clase State

#include "State.h"

// Constructor de la clase State
State::State(int a0, int a1, State *parent, string operation) {
    this->a0 = a0;
    this->a1 = a1;
    this->parent = parent;
    this->operation = operation;
}

// Metodo que imprime el estado y toda la secuencia de operaciones que lo generaron
void State::print() {
    if (parent != nullptr) {
        parent->print();
    }
    cout << "a0: " << a0 << " a1: " << a1 << " parent: "<< parent << " operation: " << operation << endl;
}