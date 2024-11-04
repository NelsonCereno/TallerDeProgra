#include "Utils.h"

// Definición de la función readFile que lee un archivo y llena las capacidades, el estado objetivo y el número de bidones.
void readFile(const string& filename, int*& capacities, int*& goal, int& num_bidones) {
    ifstream file(filename); // Abre el archivo para lectura
    if (!file.is_open()) { // Verifica si el archivo se abrió correctamente
        cerr << "Error al abrir el archivo " << filename << endl; // Muestra un mensaje de error si no se pudo abrir el archivo
        exit(1); // Termina el programa con un código de error
    }

    // Variables temporales para almacenar las capacidades y el estado objetivo
    int temp_capacities[100]; // Asumimos un máximo de 100 bidones
    int temp_goal[100];
    num_bidones = 0; // Inicializa el número de bidones a 0

    // Lee las capacidades de los bidones del archivo
    while (file >> temp_capacities[num_bidones]) {
        num_bidones++; // Incrementa el número de bidones leídos
        if (file.peek() == '\n') break; // Si se encuentra un salto de línea, termina la lectura de capacidades
    }

    // Lee el estado objetivo de los bidones del archivo
    for (int i = 0; i < num_bidones; ++i) {
        file >> temp_goal[i];
    }

    // Asigna memoria para las capacidades y el estado objetivo
    capacities = new int[num_bidones];
    goal = new int[num_bidones];

    // Copia los valores leídos a las variables de salida
    for (int i = 0; i < num_bidones; ++i) {
        capacities[i] = temp_capacities[i];
        goal[i] = temp_goal[i];
    }

    file.close(); // Cierra el archivo
}