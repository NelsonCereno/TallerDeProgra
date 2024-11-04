#include "State.h"
#include <iostream>

int main() {
    int bidones[] = {1, 2, 3}; // Estado inicial de los bidones
    int goal[] = {3, 2, 1}; // Estado objetivo de los bidones
    State state(bidones, 3, nullptr, "init"); // Crea un estado inicial con los bidones, sin estado padre y con la acción "init"

    state.print(); // Imprime el estado inicial

    if (state.isGoal(goal)) { // Verifica si el estado inicial es el estado objetivo
        std::cout << "State is goal" << std::endl; // Imprime si el estado es el objetivo
    } else {
        std::cout << "State is not goal" << std::endl; // Imprime si el estado no es el objetivo
    }

    std::cout << "Heuristic: " << state.calculateHeuristic(goal) << std::endl; // Calcula e imprime la heurística del estado

    return 0; // Termina el programa
}