#include <iostream>
#include <string>
#include "State.h"

using namespace std;

// Esta es una cola circular
// Se implementa con un arreglo de punteros a State
class Queue{
    public:
    State **arr;
    int front; // indice del primer elemento
    int back; // indice del ultimo elemento
    int size; // tamaño del arreglo

    Queue(); // crea una cola por defecto
    Queue(int n); // crea una cola de tamaño n
    int number_elements(); // cantidad de elementos de la cola
    void push(State *s); // inserta un puntero a un estado
    State * pop(); // saca el ṕrimer elemento de la cola 
    bool find(State *s); // revisar si existe un estado con igual cantidad de agua en cada botella 
};

