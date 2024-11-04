#include "HashTable.h"
#include "State.h"
#include <iostream>

int main() {
    int bidones1[] = {1, 2, 3}; // Estado inicial de los bidones para state1
    int bidones2[] = {3, 2, 1}; // Estado inicial de los bidones para state2
    int goal[] = {3, 2, 1}; // Estado objetivo de los bidones
    State state1(bidones1, 3, nullptr, "init"); // Crea un estado inicial con los bidones, sin estado padre y con la acción "init"
    State state2(bidones2, 3, nullptr, "init"); // Crea otro estado inicial con los bidones, sin estado padre y con la acción "init"

    HashTable table(10); // Crea una tabla hash con tamaño 10
    table.insert(&state1); // Inserta state1 en la tabla hash
    table.insert(&state2); // Inserta state2 en la tabla hash

    if (table.find(&state1)) { // Verifica si state1 está en la tabla hash
        std::cout << "State1 found" << std::endl; // Imprime si state1 fue encontrado
    } else {
        std::cout << "State1 not found" << std::endl; // Imprime si state1 no fue encontrado
    }

    if (table.find(&state2)) { // Verifica si state2 está en la tabla hash
        std::cout << "State2 found" << std::endl; // Imprime si state2 fue encontrado
    } else {
        std::cout << "State2 not found" << std::endl; // Imprime si state2 no fue encontrado
    }

    table.remove(&state1); // Elimina state1 de la tabla hash

    if (!table.find(&state1)) { // Verifica si state1 ya no está en la tabla hash
        std::cout << "State1 removed successfully" << std::endl; // Imprime si state1 fue eliminado exitosamente
    } else {
        std::cout << "State1 not removed" << std::endl; // Imprime si state1 no fue eliminado
    }

    return 0; // Termina el programa
}