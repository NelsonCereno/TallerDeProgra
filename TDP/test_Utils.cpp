#include "Utils.h"
#include <iostream>

int main() {
    int* capacities; // Puntero para almacenar las capacidades de los bidones
    int* goal; // Puntero para almacenar el estado objetivo de los bidones
    int num_bidones; // Variable para almacenar el número de bidones

    // Llama a la función readFile para leer los datos del archivo "pruebaUtils.txt"
    readFile("pruebaUtils.txt", capacities, goal, num_bidones);

    // Imprime las capacidades de los bidones
    std::cout << "Capacities: ";
    for (int i = 0; i < num_bidones; ++i) {
        std::cout << capacities[i] << " ";
    }
    std::cout << std::endl;

    // Imprime el estado objetivo de los bidones
    std::cout << "Goal: ";
    for (int i = 0; i < num_bidones; ++i) {
        std::cout << goal[i] << " ";
    }
    std::cout << std::endl;

    // Libera la memoria asignada para las capacidades y el estado objetivo
    delete[] capacities;
    delete[] goal;

    return 0; // Termina el programa
}