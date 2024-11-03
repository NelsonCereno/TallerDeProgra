#include "State.h"
#include <cmath>
#include <algorithm>

State::State(int* bidones, int num_bidones, State* parent, const std::string& action) {
    this->bidones = new int[num_bidones];
    this->num_bidones = num_bidones;
    this->parent = parent;
    this->action = action;
    for (int i = 0; i < num_bidones; ++i) {
        this->bidones[i] = bidones[i];
    }
    this->h = 0;
}

State::~State() {
    delete[] bidones;
}

void State::print() {
    for (int i = 0; i < num_bidones; ++i) {
        std::cout << bidones[i] << " ";
    }
    std::cout << " (" << action << ")" << std::endl;
}

bool State::isGoal(int* goal) {
    for (int i = 0; i < num_bidones; ++i) {
        if (bidones[i] != goal[i]) {
            return false;
        }
    }
    return true;
}

int State::calculateHeuristic(int* goal) {
    h = calculateManhattanDistance(goal);
    return h;
}

int State::calculateManhattanDistance(int* goal) {
    int distance = 0;
    for (int i = 0; i < num_bidones; ++i) {
        distance += std::abs(bidones[i] - goal[i]);
    }
    return distance;
}