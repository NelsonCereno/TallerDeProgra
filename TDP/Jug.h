#ifndef JUG_H
#define JUG_H

#include "State.h"
#include "HashTable.h"

class Jug {
public:
    Jug(int* capacities, int* goal, int num_bidones);
    ~Jug();
    State* solve();

private:
    int num_bidones;
    int* capacities;
    int* goal;
    HashTable* open; // Cambiado de Queue a HashTable
    HashTable* closed; // Cambiado de Queue a HashTable

    State** getSuccessors(State* current, int& num_successors);
    State* fillBidon(State* current, int i);
    State* emptyBidon(State* current, int i);
    State* transferBidon(State* current, int i, int j);
};

#endif // JUG_H