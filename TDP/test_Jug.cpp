// test_Jug.cpp
#include "Jug.h"
#include "State.h"
#include <iostream>

int main() {
    int capacities[] = {3, 5, 7}; // Capacidades de los bidones
    int goal[] = {0, 0, 5}; // Estado objetivo
    int num_bidones = 3; // Número de bidones

    Jug jug(capacities, goal, num_bidones); // Crea un objeto Jug con las capacidades, el estado objetivo y el número de bidones
    State* solution = jug.solve(); // Resuelve el problema y obtiene el estado solución

    if (solution) {
        std::cout << "Solution found:" << std::endl;
        solution->print(); // Imprime el estado solución
    } else {
        std::cout << "No solution found" << std::endl; // Imprime si no se encontró una solución
    }

    return 0; // Termina el programa
}