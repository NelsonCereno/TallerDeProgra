#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class State {
public:
    State(int* bidones, int num_bidones, State* parent, const std::string& action);
    ~State();
    void print();
    bool isGoal(int* goal);
    int calculateHeuristic(int* goal);

    int* bidones;
    int num_bidones;
    State* parent;
    std::string action;
    int h; // Heurística

private:
    int calculateManhattanDistance(int* goal);
};

#endif // STATE_H