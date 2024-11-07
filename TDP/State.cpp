#include "State.h"
#include <cmath>

// Constructor que inicializa el estado con los bidones, el número de bidones, el estado padre y la acción realizada
State::State(int* bidones, int num_bidones, State* parent, const std::string& action) {
    this->bidones = new int[num_bidones]; // Asigna memoria para los bidones
    this->num_bidones = num_bidones; // Inicializa el número de bidones
    this->parent = parent; // Inicializa el estado padre
    this->action = action; // Inicializa la acción realizada
    for (int i = 0; i < num_bidones; ++i) {
        this->bidones[i] = bidones[i]; // Copia los valores de los bidones
    }
    this->h = 0; // Inicializa la heurística a 0
}

// Destructor que libera la memoria asignada para los bidones
State::~State() {
    delete[] bidones;
}

// Método para imprimir el estado actual
void State::print() {
    for (int i = 0; i < num_bidones; ++i) {
        std::cout << bidones[i] << " "; // Imprime la cantidad de agua en cada bidón
    }
    std::cout << " (" << action << ")" << std::endl; // Imprime la acción realizada
}

// Método que verifica si el estado actual es el estado objetivo
bool State::isGoal(int* goal) {
    for (int i = 0; i < num_bidones; ++i) {
        if (bidones[i] != goal[i]) { // Compara cada bidón con el estado objetivo
            return false; // Si algún bidón no coincide, retorna false
        }
    }
    return true; // Si todos los bidones coinciden, retorna true
}

// Método que calcula la heurística del estado actual en función del estado objetivo
int State::calculateHeuristic(int* goal) {
    h = calculateBrayCurtisDistance(goal); // Cambiado a Bray-Curtis
    return h; // Retorna el valor de la heurística
}

// Método privado que calcula la distancia de Manhattan entre el estado actual y el estado objetivo
int State::calculateManhattanDistance(int* goal) {
    int distance = 0;
    for (int i = 0; i < num_bidones; ++i) {
        distance += std::abs(bidones[i] - goal[i]); // Suma la diferencia absoluta entre cada bidón y el estado objetivo
    }
    return distance; // Retorna la distancia de Manhattan
}

int State::calculateBrayCurtisDistance(int* goal) {
    int sum_diff = 0;
    int sum_total = 0;
    for (int i = 0; i < num_bidones; ++i) {
        sum_diff += std::abs(bidones[i] - goal[i]);
        sum_total += (bidones[i] + goal[i]);
    }
    return sum_total == 0 ? 0 : (sum_diff / sum_total);
}