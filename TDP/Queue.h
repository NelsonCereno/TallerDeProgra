#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "State.h"

using namespace std;

class Queue {
public:
    State **arr;
    int front; // índice del primer elemento
    int back; // índice del último elemento
    int size; // tamaño del arreglo

    Queue(); // crea una cola por defecto
    Queue(int n); // crea una cola de tamaño n
    ~Queue();
    int number_elements(); // cantidad de elementos de la cola
    void push(State *s); // inserta un puntero a un estado
    State *pop(); // saca el primer elemento de la cola 
    bool find(State *s); // revisar si existe un estado con igual cantidad de agua en cada botella 
    void resize(); // redimensiona la cola
};

#endif // QUEUE_H