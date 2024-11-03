
#include "utils.h"

void readFile(const string& filename, int*& capacities, int*& goal, int& num_bidones) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << endl;
        exit(1);
    }

    // Leer las capacidades
    int temp_capacities[100]; // Asumimos un máximo de 100 bidones
    int temp_goal[100];
    num_bidones = 0;

    while (file >> temp_capacities[num_bidones]) {

        num_bidones++;
        if (file.peek() == '\n') break;
        
    }

    // Leer el estado objetivo
    for (int i = 0; i < num_bidones; ++i) {
        file >> temp_goal[i];
    }

    capacities = new int[num_bidones];
    goal = new int[num_bidones];

    for (int i = 0; i < num_bidones; ++i) {
        capacities[i] = temp_capacities[i];
        goal[i] = temp_goal[i];
    }

    file.close();
}