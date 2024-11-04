#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "State.h"

// Estructura para representar un nodo en la tabla hash
struct HashNode {
    State* state; // Puntero al estado almacenado en el nodo
    HashNode* next; // Puntero al siguiente nodo en la lista enlazada
};

// Clase HashTable para manejar una tabla hash de estados
class HashTable {
public:
    // Constructor que inicializa la tabla hash con un tamaño dado
    HashTable(int size);
    
    // Destructor que libera la memoria asignada para la tabla hash
    ~HashTable();
    
    // Método para insertar un estado en la tabla hash
    bool insert(State* state);
    
    // Método para buscar un estado en la tabla hash
    bool find(State* state);
    
    // Método para eliminar un estado de la tabla hash
    bool remove(State* state);
    
    // Método para extraer un estado de la tabla hash
    State* extract();
    
    // Método para obtener el número de elementos en la tabla hash
    int number_elements();

private:
    // Método privado para calcular el hash de un estado
    int hashFunction(State* state);
    
    HashNode** table; // Arreglo de punteros a nodos de la tabla hash
    int size; // Tamaño de la tabla hash
};

#endif // HASHTABLE_H