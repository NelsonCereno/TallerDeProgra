#include "Jug.h"
#include <iostream>
#include <algorithm>

Jug::Jug(int* capacities, int* goal, int num_bidones) {
    this->num_bidones = num_bidones;
    this->capacities = new int[num_bidones];
    this->goal = new int[num_bidones];
    for (int i = 0; i < num_bidones; ++i) {
        this->capacities[i] = capacities[i];
        this->goal[i] = goal[i];
    }
    open = new HashTable(1000); // tamaño inicial arbitrario
    closed = new HashTable(1000); // tamaño inicial arbitrario
    int* initial = new int[num_bidones]();
    State *initialState = new State(initial, num_bidones, nullptr, "init");
    initialState->calculateHeuristic(goal);
    open->insert(initialState);
    closed->insert(initialState);
    delete[] initial;
}

Jug::~Jug() {
    delete[] capacities;
    delete[] goal;
    delete open;
    delete closed;
}

State* Jug::solve() {
    while (open->number_elements() > 0) {
        State *current = open->extract();
        std::cout << "Explorando estado: ";
        current->print();

        if (current->isGoal(goal)) {
            return current;
        }

        int num_successors;
        State** successors = getSuccessors(current, num_successors);

        // Ordenar sucesores por heurística antes de insertarlos en open
        std::sort(successors, successors + num_successors, [this](State* a, State* b) {
            return a->calculateHeuristic(goal) < b->calculateHeuristic(goal);
        });

        for (int i = 0; i < num_successors; ++i) {
            State* successor = successors[i];
            if (!closed->find(successor)) {
                open->insert(successor);
                closed->insert(successor);
            } else {
                delete successor;
            }
        }
        delete[] successors;
    }
    return nullptr;
}

State** Jug::getSuccessors(State* current, int& num_successors) {
    num_successors = 0;
    State** successors = new State*[num_bidones * 2 + num_bidones * (num_bidones - 1)];

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
    return successors;
}

State* Jug::fillBidon(State* current, int i) {
    int* new_bidones = new int[num_bidones];
    for (int j = 0; j < num_bidones; ++j) {
        new_bidones[j] = current->bidones[j];
    }
    new_bidones[i] = capacities[i];
    State* newState = new State(new_bidones, num_bidones, current, "fill " + std::to_string(i));
    delete[] new_bidones;
    return newState;
}

State* Jug::emptyBidon(State* current, int i) {
    int* new_bidones = new int[num_bidones];
    for (int j = 0; j < num_bidones; ++j) {
        new_bidones[j] = current->bidones[j];
    }
    new_bidones[i] = 0;
    State* newState = new State(new_bidones, num_bidones, current, "empty " + std::to_string(i));
    delete[] new_bidones;
    return newState;
}

State* Jug::transferBidon(State* current, int i, int j) {
    int* new_bidones = new int[num_bidones];
    for (int k = 0; k < num_bidones; ++k) {
        new_bidones[k] = current->bidones[k];
    }
    int transfer_amount = std::min(current->bidones[i], capacities[j] - current->bidones[j]);
    new_bidones[i] -= transfer_amount;
    new_bidones[j] += transfer_amount;
    State* newState = new State(new_bidones, num_bidones, current, "transfer " + std::to_string(i) + " to " + std::to_string(j));
    delete[] new_bidones;
    return newState;
}