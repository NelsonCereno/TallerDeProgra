#include "Queue.h"

// Constructor por defecto
Queue::Queue() {
    arr = nullptr; // Inicializa el arreglo a nullptr
    front = -1; // Inicializa el índice del primer elemento a -1
    back = -1; // Inicializa el índice del último elemento a -1
    size = -1; // Inicializa el tamaño del arreglo a -1
}

// Constructor que crea una cola de tamaño n
Queue::Queue(int n) {
    arr = new State*[n]; // Asigna memoria para un arreglo de n elementos de tipo State*
    size = n; // Asigna el tamaño del arreglo
    front = -1; // Inicializa el índice del primer elemento a -1
    back = -1; // Inicializa el índice del último elemento a -1
}

// Destructor
Queue::~Queue() {
    delete[] arr; // Libera la memoria asignada para el arreglo
}

// Método para obtener la cantidad de elementos en la cola
int Queue::number_elements() {
    if (back == -1 && front == -1) {
        return 0; // Si la cola está vacía, retorna 0
    }
    if (back >= front) {
        return (back - front + 1); // Si el índice del último elemento es mayor o igual al del primer elemento, retorna la diferencia más 1
    } else {
        return (size - front + back + 1); // Si el índice del último elemento es menor al del primer elemento, retorna el tamaño del arreglo menos el índice del primer elemento más el índice del último elemento más 1
    }
}

// Método para sacar el primer elemento de la cola
State* Queue::pop() {
    if (number_elements() == 0) { // Si la cola está vacía
        return nullptr; // Retorna nullptr
    } else {
        State* s = arr[front]; // Obtiene el primer elemento de la cola
        if (number_elements() == 1) {
            front = back = -1; // Si la cola tiene un solo elemento, reinicia los índices
        } else if (front == size - 1) {
            front = 0; // Si el índice del primer elemento es el último del arreglo, lo reinicia a 0
        } else {
            front++; // Incrementa el índice del primer elemento
        }
        return s; // Retorna el primer elemento de la cola
    }
}

// Método para insertar un puntero a un estado en la cola
void Queue::push(State* s) {
    if (number_elements() == size) { // Si la cola está llena
        resize(); // Redimensiona la cola
    }

    if (number_elements() == 0) { // Si la cola está vacía
        front = back = 0; // Inicializa los índices a 0
    } else if (back == size - 1) { // Si el índice del último elemento es el último del arreglo
        back = 0; // Lo reinicia a 0
    } else {
        back = (back + 1) % size; // Incrementa el índice del último elemento
    }
    arr[back] = s; // Asigna el estado al índice del último elemento
}

// Método para revisar si existe un estado con igual cantidad de agua en cada bidón
bool Queue::find(State* s) {
    if (front == -1 && back == -1) {
        return false; // Si la cola está vacía, retorna false
    }
    if (back >= front) {
        for (int k = front; k <= back; k++) {
            if (arr[k]->isGoal(s->bidones)) { // Compara cada estado en la cola con el estado dado
                return true; // Si encuentra un estado igual, retorna true
            }
        }
    } else {
        for (int k = front; k <= size - 1; k++) {
            if (arr[k]->isGoal(s->bidones)) { // Compara cada estado en la cola con el estado dado
                return true; // Si encuentra un estado igual, retorna true
            }
        }
        for (int k = 0; k <= back; k++) {
            if (arr[k]->isGoal(s->bidones)) { // Compara cada estado en la cola con el estado dado
                return true; // Si encuentra un estado igual, retorna true
            }
        }
    }
    return false; // Si no encuentra un estado igual, retorna false
}

// Método para redimensionar la cola
void Queue::resize() {
    int newSize = size * 2; // Duplica el tamaño del arreglo
    State** newArr = new State*[newSize]; // Asigna memoria para un nuevo arreglo de tamaño duplicado
    if (back >= front) {
        for (int i = front; i <= back; ++i) {
            newArr[i - front] = arr[i]; // Copia los elementos del arreglo original al nuevo arreglo
        }
    } else {
        int index = 0;
        for (int i = front; i < size; ++i) {
            newArr[index++] = arr[i]; // Copia los elementos del arreglo original al nuevo arreglo
        }
        for (int i = 0; i <= back; ++i) {
            newArr[index++] = arr[i]; // Copia los elementos del arreglo original al nuevo arreglo
        }
    }
    front = 0; // Reinicia el índice del primer elemento a 0
    back = number_elements() - 1; // Actualiza el índice del último elemento
    size = newSize; // Actualiza el tamaño del arreglo
    delete[] arr; // Libera la memoria del arreglo original
    arr = newArr; // Asigna el nuevo arreglo al arreglo original
}