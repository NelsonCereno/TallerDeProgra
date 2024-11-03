#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"

struct HashNode {
    State* state;
    HashNode* next;
};

class HashTable {
public:
    HashTable(int size);
    ~HashTable();
    bool insert(State* state);
    bool find(State* state);
    bool remove(State* state);
    State* extract();
    int number_elements();

private:
    int hashFunction(State* state);
    HashNode** table;
    int size;
};

#endif // HASHTABLE_H