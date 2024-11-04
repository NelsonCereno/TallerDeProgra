#include <iostream>
#include <string>
#include <chrono>
#include "Jug.h"
#include "Utils.h"

using namespace std;
using namespace std::chrono;

int main() {
    string filename; // Variable para almacenar el nombre del archivo
    cout << "Ingrese el nombre del archivo: "; // Solicita al usuario que ingrese el nombre del archivo
    cin >> filename; // Lee el nombre del archivo ingresado por el usuario

    int* capacities; // Puntero para almacenar las capacidades de los bidones
    int* goal; // Puntero para almacenar el estado objetivo de los bidones
    int num_bidones; // Variable para almacenar el número de bidones
    readFile(filename, capacities, goal, num_bidones); // Llama a la función readFile para leer los datos del archivo

    Jug j(capacities, goal, num_bidones); // Crea un objeto Jug con las capacidades, el estado objetivo y el número de bidones

    // Medir el tiempo de ejecución de solve
    auto start = high_resolution_clock::now(); // Obtiene el tiempo de inicio
    State* solution = j.solve(); // Llama al método solve para resolver el problema y obtener el estado solución
    auto end = high_resolution_clock::now(); // Obtiene el tiempo de finalización

    auto duration = duration_cast<milliseconds>(end - start).count(); // Calcula la duración en milisegundos
    cout << "Tiempo de ejecución de solve: " << duration << " ms" << endl; // Imprime el tiempo de ejecución

    if (solution) { // Si se encontró una solución
        cout << "Solution found:" << endl; // Imprime que se encontró una solución
        solution->print(); // Imprime el estado solución
    } else { // Si no se encontró una solución
        cout << "No solution found" << endl; // Imprime que no se encontró una solución
    }

    delete[] capacities; // Libera la memoria asignada para las capacidades
    delete[] goal; // Libera la memoria asignada para el estado objetivo

    return 0; // Termina el programa
}