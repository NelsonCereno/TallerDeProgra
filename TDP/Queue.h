#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "State.h"

using namespace std;

class Queue {
public:
    State **arr; // Arreglo de punteros a objetos de tipo State
    int front; // Índice del primer elemento
    int back; // Índice del último elemento
    int size; // Tamaño del arreglo

    Queue(); // Constructor por defecto
    Queue(int n); // Constructor que crea una cola de tamaño n
    ~Queue(); // Destructor
    int number_elements(); // Método para obtener la cantidad de elementos en la cola
    void push(State *s); // Método para insertar un puntero a un estado en la cola
    State *pop(); // Método para sacar el primer elemento de la cola 
    bool find(State *s); // Método para revisar si existe un estado con igual cantidad de agua en cada bidón 
    void resize(); // Método para redimensionar la cola
};

#endif // QUEUE_H