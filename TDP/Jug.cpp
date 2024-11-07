#include "Jug.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor que inicializa el problema con las capacidades de los bidones, el estado objetivo y el número de bidones
Jug::Jug(int* capacities, int* goal, int num_bidones) {
    this->num_bidones = num_bidones;
    this->capacities = new int[num_bidones];
    this->goal = new int[num_bidones];
    for (int i = 0; i < num_bidones; ++i) {
        this->capacities[i] = capacities[i];
        this->goal[i] = goal[i];
    }
    open = new Queue(1000);
    closed = new HashTable(1000);
    int* initial = new int[num_bidones]();
    State *initialState = new State(initial, num_bidones, nullptr, "init");
    initialState->calculateHeuristic(goal);
    open->push(initialState);
    closed->insert(initialState);
    delete[] initial;

    std::srand(std::time(0));
}

Jug::~Jug() {
    delete[] capacities;
    delete[] goal;
    delete open;
    delete closed;
}

State* Jug::solve() {
    int step_counter = 0;
    const int RANDOM_STEP_INTERVAL = 10;

    while (open->number_elements() > 0) {
        State *current;
        if (step_counter % RANDOM_STEP_INTERVAL == 0 && open->number_elements() > 1) {
            int random_index = std::rand() % open->number_elements();
            for (int i = 0; i < random_index; ++i) {
                open->push(open->pop());
            }
            current = open->pop();
        } else {
            current = open->pop();
        }

        std::cout << "Explorando estado: ";
        current->print();

        if (current->isGoal(goal)) {
            return current;
        }

        int num_successors;
        State** successors = getSuccessors(current, num_successors);
        sortSuccessors(successors, num_successors);

        for (int i = 0; i < num_successors; ++i) {
            State* successor = successors[i];
            if (!closed->find(successor)) {
                open->push(successor);
                closed->insert(successor);
            } else {
                delete successor;
            }
        }
        delete[] successors;

        step_counter++;
    }
    return nullptr;
}

State** Jug::getSuccessors(State* current, int& num_successors) {
    num_successors = 0;
    State** successors = new State*[num_bidones * 2 + num_bidones * (num_bidones - 1)];

    for (int i = 0; i < num_bidones; ++i) {
        if (current->bidones[i] < capacities[i]) {
            State* newState = fillBidon(current, i);
            if (newState) {
                successors[num_successors++] = newState;
            }
        }
        if (current->bidones[i] > 0) {
            State* newState = emptyBidon(current, i);
            if (newState) {
                successors[num_successors++] = newState;
            }
        }
        for (int j = 0; j < num_bidones; ++j) {
            if (i != j && current->bidones[i] > 0 && current->bidones[j] < capacities[j]) {
                State* newState = transferBidon(current, i, j);
                if (newState) {
                    successors[num_successors++] = newState;
                }
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
    int transfer_amount = min(current->bidones[i], capacities[j] - current->bidones[j]);
    new_bidones[i] -= transfer_amount;
    new_bidones[j] += transfer_amount;

    State* newState = new State(new_bidones, num_bidones, current, "transfer " + std::to_string(i) + " to " + std::to_string(j));
    delete[] new_bidones;
    return newState;
}

void Jug::sortSuccessors(State** successors, int num_successors) {
    quickSort(successors, 0, num_successors - 1);
}

void Jug::quickSort(State** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Jug::partition(State** arr, int low, int high) {
    State* pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j]->h < pivot->h) {
            i++;
            State* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    State* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

int Jug::min(int a, int b) {
    return (a < b) ? a : b;
}