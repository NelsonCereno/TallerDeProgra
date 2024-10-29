#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

class Jug {
    public:
    Queue *open; // almacena los estado por visitar
    Queue *all; // almacena todos los estados
    Jug(int sizeopen, int sizeall); // construye con tamaños de open y all; en open agrega un estado con botellas vacias
    State* fill0(State *origin); // llenar botella 0
    State* fill1(State *origin); // llenar botella 1
    State* empty0(State *origin);
    State* empty1(State *origin);
    State* transfer01(State *origin);
    State* transfer10(State *origin);
    State* solve(); // retorna el estado solucion
};
