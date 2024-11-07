#ifndef JUG_H
#define JUG_H

#include "State.h"
#include "Queue.h"
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
    Queue* open;
    HashTable* closed;

    State** getSuccessors(State* current, int& num_successors);
    State* fillBidon(State* current, int i);
    State* emptyBidon(State* current, int i);
    State* transferBidon(State* current, int i, int j);
    void sortSuccessors(State** successors, int num_successors);
    int min(int a, int b);

    void quickSort(State** arr, int low, int high);
    int partition(State** arr, int low, int high);
};

#endif // JUG_H