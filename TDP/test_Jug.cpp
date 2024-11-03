// test_Jug.cpp
#include "Jug.h"

int main() {
    int capacities[] = {3, 5, 7, 11}; // capacidades de los bidones
    int goal[] = {0, 0, 0, 10}; // estado objetivo
    int num_bidones = 4;

    Jug j(capacities, goal, num_bidones);
    State *solution = j.solve();
    if (solution) {
        solution->print();
    } else {
        cout << "No solution found" << endl;
    }
    return 0;
}