#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFile(const string& filename, int*& capacities, int*& goal, int& num_bidones);

#endif // UTILS_H