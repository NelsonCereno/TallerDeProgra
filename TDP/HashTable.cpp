#include "HashTable.h"
#include <cstring>

// Constructor que inicializa la tabla hash con un tamaño dado
HashTable::HashTable(int size) {
    this->size = size; // Asigna el tamaño de la tabla hash
    table = new HashNode*[size]; // Asigna memoria para el arreglo de punteros a nodos
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr; // Inicializa cada entrada de la tabla hash a nullptr
    }
}

// Destructor que libera la memoria asignada para la tabla hash
HashTable::~HashTable() {
    for (int i = 0; i < size; ++i) {
        HashNode* entry = table[i]; // Obtiene la entrada actual de la tabla hash
        while (entry != nullptr) {
            HashNode* prev = entry; // Guarda el nodo actual
            entry = entry->next; // Avanza al siguiente nodo
            delete prev; // Libera la memoria del nodo actual
        }
    }
    delete[] table; // Libera la memoria del arreglo de punteros a nodos
}

// Método privado que calcula el hash de un estado
int HashTable::hashFunction(State* state) {
    int hash = 0;
    for (int i = 0; i < state->num_bidones; ++i) {
        hash = (hash + state->bidones[i]) % size; // Calcula el hash sumando los valores de los bidones y aplicando módulo con el tamaño de la tabla
    }
    return hash; // Retorna el valor del hash
}

// Método para insertar un estado en la tabla hash
bool HashTable::insert(State* state) {
    int hash = hashFunction(state); // Calcula el hash del estado
    HashNode* newNode = new HashNode; // Crea un nuevo nodo
    newNode->state = state; // Asigna el estado al nuevo nodo
    newNode->next = table[hash]; // Inserta el nuevo nodo al inicio de la lista enlazada en la posición del hash
    table[hash] = newNode; // Actualiza la tabla hash con el nuevo nodo
    return true; // Retorna true indicando que la inserción fue exitosa
}

// Método para buscar un estado en la tabla hash
bool HashTable::find(State* state) {
    int hash = hashFunction(state); // Calcula el hash del estado
    HashNode* entry = table[hash]; // Obtiene la entrada de la tabla hash en la posición del hash
    while (entry != nullptr) {
        bool same = true;
        for (int i = 0; i < state->num_bidones; ++i) {
            if (entry->state->bidones[i] != state->bidones[i]) { // Compara cada bidón del estado con el estado en el nodo
                same = false;
                break;
            }
        }
        if (same) {
            return true; // Si todos los bidones coinciden, retorna true
        }
        entry = entry->next; // Avanza al siguiente nodo en la lista enlazada
    }
    return false; // Si no se encuentra el estado, retorna false
}

// Método para eliminar un estado de la tabla hash
bool HashTable::remove(State* state) {
    int hash = hashFunction(state); // Calcula el hash del estado
    HashNode* entry = table[hash]; // Obtiene la entrada de la tabla hash en la posición del hash
    HashNode* prev = nullptr; // Puntero al nodo previo
    while (entry != nullptr) {
        bool same = true;
        for (int i = 0; i < state->num_bidones; ++i) {
            if (entry->state->bidones[i] != state->bidones[i]) { // Compara cada bidón del estado con el estado en el nodo
                same = false;
                break;
            }
        }
        if (same) {
            if (prev == nullptr) {
                table[hash] = entry->next; // Si el nodo a eliminar es el primero, actualiza la tabla hash
            } else {
                prev->next = entry->next; // Si no, actualiza el puntero del nodo previo
            }
            delete entry; // Libera la memoria del nodo eliminado
            return true; // Retorna true indicando que la eliminación fue exitosa
        }
        prev = entry; // Actualiza el puntero previo
        entry = entry->next; // Avanza al siguiente nodo en la lista enlazada
    }
    return false; // Si no se encuentra el estado, retorna false
}

// Método para extraer un estado de la tabla hash
State* HashTable::extract() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr) {
            State* state = table[i]->state; // Obtiene el estado del primer nodo en la lista enlazada
            remove(state); // Elimina el estado de la tabla hash
            return state; // Retorna el estado extraído
        }
    }
    return nullptr; // Si no se encuentra ningún estado, retorna nullptr
}

// Método para obtener el número de elementos en la tabla hash
int HashTable::number_elements() {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        HashNode* entry = table[i]; // Obtiene la entrada actual de la tabla hash
        while (entry != nullptr) {
            count++; // Incrementa el contador por cada nodo en la lista enlazada
            entry = entry->next; // Avanza al siguiente nodo en la lista enlazada
        }
    }
    return count; // Retorna el número total de elementos en la tabla hash
}