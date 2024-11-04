#ifndef JUG_H
#define JUG_H

#include "State.h"
#include "HashTable.h"

class Jug {
public:
    // Constructor que inicializa el problema con las capacidades de los bidones, el estado objetivo y el número de bidones
    Jug(int* capacities, int* goal, int num_bidones);
    
    // Destructor que libera la memoria asignada
    ~Jug();
    
    // Método que resuelve el problema y retorna el estado solución
    State* solve();

private:
    int num_bidones; // Número de bidones
    int* capacities; // Capacidades de los bidones
    int* goal; // Estado objetivo
    HashTable* open; // Tabla hash para los estados abiertos (por explorar)
    HashTable* closed; // Tabla hash para los estados cerrados (ya explorados)

    // Método que obtiene los sucesores de un estado dado
    State** getSuccessors(State* current, int& num_successors);
    
    // Métodos para llenar, vaciar y transferir entre bidones
    State* fillBidon(State* current, int i);
    State* emptyBidon(State* current, int i);
    State* transferBidon(State* current, int i, int j);
};

#endif // JUG_H