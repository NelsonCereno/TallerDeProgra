#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Declaración de la función readFile que lee un archivo y llena las capacidades, el estado objetivo y el número de bidones.
void readFile(const string& filename, int*& capacities, int*& goal, int& num_bidones);

#endif // UTILS_H