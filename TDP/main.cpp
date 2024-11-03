#include <iostream>
#include <chrono>
#include "Jug.h"
#include "utils.h"

using namespace std;
using namespace std::chrono;

void showMenu() {
    cout << "Seleccione la dificultad:" << endl;
    cout << "1. Facil" << endl;
    cout << "2. Medio" << endl;
    cout << "3. Dificil" << endl;
    cout << "Opción: ";
}

int main() {
    int option;
    showMenu();
    cin >> option;

    string filename;
    switch (option) {
        case 1:
            filename = "facil.txt";
            break;
        case 2:
            filename = "medio.txt";
            break;
        case 3:
            filename = "dificil.txt";
            break;
        default:
            cout << "Opción no válida" << endl;
            return 1;
    }

    int* capacities;
    int* goal;
    int num_bidones;
    readFile(filename, capacities, goal, num_bidones);

    Jug j(capacities, goal, num_bidones);

    // Medir el tiempo de ejecución de solve
    auto start = high_resolution_clock::now();
    State *solution = j.solve();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Tiempo de ejecución de solve: " << duration << " ms" << endl;

    if (solution) {
        solution->print();
    } else {
        cout << "No solution found" << endl;
    }

    delete[] capacities;
    delete[] goal;

    return 0;
}