#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class State {
public:
    // Constructor que inicializa el estado con los bidones, el número de bidones, el estado padre y la acción realizada
    State(int* bidones, int num_bidones, State* parent, const std::string& action);
    
    // Destructor que libera la memoria asignada para los bidones
    ~State();
    
    // Método para imprimir el estado actual
    void print();
    
    // Método que verifica si el estado actual es el estado objetivo
    bool isGoal(int* goal);
    
    // Método que calcula la heurística del estado actual en función del estado objetivo
    int calculateHeuristic(int* goal);

    // Atributos públicos
    int* bidones; // Arreglo que almacena la cantidad de agua en cada bidón
    int num_bidones; // Número de bidones
    State* parent; // Puntero al estado padre
    std::string action; // Acción realizada para llegar a este estado
    int h; // Valor de la heurística

private:
    // Método privado que calcula la distancia de Manhattan entre el estado actual y el estado objetivo
    int calculateManhattanDistance(int* goal);
    int calculateBrayCurtisDistance(int* goal); // Nueva declaración
};

#endif // STATE_H