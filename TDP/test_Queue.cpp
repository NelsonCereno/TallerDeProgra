#include "Queue.h"
#include "State.h"
#include <iostream>

int main() {
    Queue queue(5); // Crea una cola con tamaño 5

    int bidones1[] = {1, 2, 3}; // Estado inicial de los bidones para state1
    int bidones2[] = {3, 2, 1}; // Estado inicial de los bidones para state2
    State state1(bidones1, 3, nullptr, "init"); // Crea un estado inicial con los bidones, sin estado padre y con la acción "init"
    State state2(bidones2, 3, nullptr, "init"); // Crea otro estado inicial con los bidones, sin estado padre y con la acción "init"

    queue.push(&state1); // Inserta state1 en la cola
    queue.push(&state2); // Inserta state2 en la cola

    std::cout << "Number of elements: " << queue.number_elements() << std::endl; // Imprime el número de elementos en la cola

    State* s = queue.pop(); // Saca el primer elemento de la cola
    if (s) {
        std::cout << "Popped state: ";
        s->print(); // Imprime el estado sacado de la cola
    }

    std::cout << "Number of elements after pop: " << queue.number_elements() << std::endl; // Imprime el número de elementos en la cola después de sacar un elemento

    return 0; // Termina el programa
}