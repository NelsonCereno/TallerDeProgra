#include "HashTable.h"
#include <cstring>

HashTable::HashTable(int size) {
    this->size = size;
    table = new HashNode*[size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < size; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            HashNode* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(State* state) {
    int hash = 0;
    for (int i = 0; i < state->num_bidones; ++i) {
        hash = (hash + state->bidones[i]) % size;
    }
    return hash;
}

bool HashTable::insert(State* state) {
    int hash = hashFunction(state);
    HashNode* newNode = new HashNode;
    newNode->state = state;
    newNode->next = table[hash];
    table[hash] = newNode;
    return true;
}

bool HashTable::find(State* state) {
    int hash = hashFunction(state);
    HashNode* entry = table[hash];
    while (entry != nullptr) {
        bool same = true;
        for (int i = 0; i < state->num_bidones; ++i) {
            if (entry->state->bidones[i] != state->bidones[i]) {
                same = false;
                break;
            }
        }
        if (same) {
            return true;
        }
        entry = entry->next;
    }
    return false;
}

bool HashTable::remove(State* state) {
    int hash = hashFunction(state);
    HashNode* entry = table[hash];
    HashNode* prev = nullptr;
    while (entry != nullptr) {
        bool same = true;
        for (int i = 0; i < state->num_bidones; ++i) {
            if (entry->state->bidones[i] != state->bidones[i]) {
                same = false;
                break;
            }
        }
        if (same) {
            if (prev == nullptr) {
                table[hash] = entry->next;
            } else {
                prev->next = entry->next;
            }
            delete entry;
            return true;
        }
        prev = entry;
        entry = entry->next;
    }
    return false;
}

State* HashTable::extract() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr) {
            State* state = table[i]->state;
            remove(state);
            return state;
        }
    }
    return nullptr;
}

int HashTable::number_elements() {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            count++;
            entry = entry->next;
        }
    }
    return count;
}