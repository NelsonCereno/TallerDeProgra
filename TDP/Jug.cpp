#include "Jug.h"
#include <iostream>
#include <algorithm>

// Constructor que inicializa el problema con las capacidades de los bidones, el estado objetivo y el número de bidones
Jug::Jug(int* capacities, int* goal, int num_bidones) {
    this->num_bidones = num_bidones;
    this->capacities = new int[num_bidones];
    this->goal = new int[num_bidones];
    for (int i = 0; i < num_bidones; ++i) {
        this->capacities[i] = capacities[i]; // Copia las capacidades de los bidones
        this->goal[i] = goal[i]; // Copia el estado objetivo
    }
    open = new HashTable(1000); // Inicializa la tabla hash para los estados abiertos con tamaño 1000
    closed = new HashTable(1000); // Inicializa la tabla hash para los estados cerrados con tamaño 1000
    int* initial = new int[num_bidones](); // Crea un estado inicial con todos los bidones vacíos
    State *initialState = new State(initial, num_bidones, nullptr, "init");
    initialState->calculateHeuristic(goal); // Calcula la heurística del estado inicial
    open->insert(initialState); // Inserta el estado inicial en la tabla hash de estados abiertos
    closed->insert(initialState); // Inserta el estado inicial en la tabla hash de estados cerrados
    delete[] initial; // Libera la memoria del estado inicial
}

// Destructor que libera la memoria asignada
Jug::~Jug() {
    delete[] capacities; // Libera la memoria de las capacidades
    delete[] goal; // Libera la memoria del estado objetivo
    delete open; // Libera la memoria de la tabla hash de estados abiertos
    delete closed; // Libera la memoria de la tabla hash de estados cerrados
}

// Método que resuelve el problema y retorna el estado solución
State* Jug::solve() {
    while (open->number_elements() > 0) { // Mientras haya estados por explorar
        State *current = open->extract(); // Extrae el siguiente estado a explorar
        std::cout << "Explorando estado: ";
        current->print(); // Imprime el estado actual

        if (current->isGoal(goal)) { // Si el estado actual es el estado objetivo
            return current; // Retorna el estado solución
        }

        int num_successors;
        State** successors = getSuccessors(current, num_successors); // Obtiene los sucesores del estado actual

        // Ordena los sucesores por heurística antes de insertarlos en la tabla hash de estados abiertos
        sortSuccessors(successors, num_successors);

        for (int i = 0; i < num_successors; ++i) {
            State* successor = successors[i];
            if (!closed->find(successor)) { // Si el sucesor no está en la tabla hash de estados cerrados
                open->insert(successor); // Inserta el sucesor en la tabla hash de estados abiertos
                closed->insert(successor); // Inserta el sucesor en la tabla hash de estados cerrados
            } else {
                delete successor; // Si el sucesor ya está en la tabla hash de estados cerrados, lo elimina
            }
        }
        delete[] successors; // Libera la memoria de los sucesores
    }
    return nullptr; // Si no se encuentra una solución, retorna nullptr
}

// Método que obtiene los sucesores de un estado dado
State** Jug::getSuccessors(State* current, int& num_successors) {
    num_successors = 0;
    State** successors = new State*[num_bidones * 2 + num_bidones * (num_bidones - 1)]; // Asigna memoria para los sucesores

    for (int i = 0; i < num_bidones; ++i) {
        // Llenar el bidón i
        if (current->bidones[i] < capacities[i]) {
            successors[num_successors++] = fillBidon(current, i);
        }
        // Vaciar el bidón i
        if (current->bidones[i] > 0) {
            successors[num_successors++] = emptyBidon(current, i);
        }
        // Transferir de i a j
        for (int j = 0; j < num_bidones; ++j) {
            if (i != j && current->bidones[i] > 0 && current->bidones[j] < capacities[j]) {
                successors[num_successors++] = transferBidon(current, i, j);
            }
        }
    }
    return successors; // Retorna los sucesores
}

// Método para llenar el bidón i
State* Jug::fillBidon(State* current, int i) {
    int* new_bidones = new int[num_bidones];
    for (int j = 0; j < num_bidones; ++j) {
        new_bidones[j] = current->bidones[j]; // Copia los valores de los bidones actuales
    }
    new_bidones[i] = capacities[i]; // Llena el bidón i
    State* newState = new State(new_bidones, num_bidones, current, "fill " + std::to_string(i)); // Crea un nuevo estado con la acción "fill i"
    delete[] new_bidones; // Libera la memoria de los bidones nuevos
    return newState; // Retorna el nuevo estado
}

// Método para vaciar el bidón i
State* Jug::emptyBidon(State* current, int i) {
    int* new_bidones = new int[num_bidones];
    for (int j = 0; j < num_bidones; ++j) {
        new_bidones[j] = current->bidones[j]; // Copia los valores de los bidones actuales
    }
    new_bidones[i] = 0; // Vacía el bidón i
    State* newState = new State(new_bidones, num_bidones, current, "empty " + std::to_string(i)); // Crea un nuevo estado con la acción "empty i"
    delete[] new_bidones; // Libera la memoria de los bidones nuevos
    return newState; // Retorna el nuevo estado
}

// Método para transferir agua del bidón i al bidón j
State* Jug::transferBidon(State* current, int i, int j) {
    int* new_bidones = new int[num_bidones];
    for (int k = 0; k < num_bidones; ++k) {
        new_bidones[k] = current->bidones[k]; // Copia los valores de los bidones actuales
    }
    int transfer_amount = min(current->bidones[i], capacities[j] - current->bidones[j]); // Calcula la cantidad de agua a transferir
    new_bidones[i] -= transfer_amount; // Resta la cantidad transferida del bidón i
    new_bidones[j] += transfer_amount; // Suma la cantidad transferida al bidón j
    State* newState = new State(new_bidones, num_bidones, current, "transfer " + std::to_string(i) + " to " + std::to_string(j)); // Crea un nuevo estado con la acción "transfer i to j"
    delete[] new_bidones; // Libera la memoria de los bidones nuevos
    return newState; // Retorna el nuevo estado
}

// Método para ordenar los sucesores por heurística
void Jug::sortSuccessors(State** successors, int num_successors) {
    for (int i = 0; i < num_successors - 1; ++i) {
        for (int j = 0; j < num_successors - i - 1; ++j) {
            if (successors[j]->calculateHeuristic(goal) > successors[j + 1]->calculateHeuristic(goal)) {
                State* temp = successors[j];
                successors[j] = successors[j + 1];
                successors[j + 1] = temp;
            }
        }
    }
}

// Método para encontrar el mínimo de dos enteros
int Jug::min(int a, int b) {
    return (a < b) ? a : b;
}