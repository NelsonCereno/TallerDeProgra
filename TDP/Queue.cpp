// Queue.cpp
#include "Queue.h"

Queue::Queue() {
    arr = nullptr;
    front = -1;
    back = -1;
    size = -1;
}

Queue::Queue(int n) {
    arr = new State*[n]; // un arreglo de n elementos de tipo State*
    size = n;
    front = -1; // definimos que una cola vacía es back=front=-1
    back = -1; // otra convención es que el push lo hacemos en back+1
}

Queue::~Queue() {
    delete[] arr;
}

int Queue::number_elements() {
    if (back == -1 && front == -1) {
        return 0;
    }
    if (back >= front) {
        return (back - front + 1);
    } else {
        return (size - front + back + 1);
    }
}

State* Queue::pop() {
    if (number_elements() == 0) { // si la cola está vacía
        return nullptr; // Si la cola está vacía retornamos nulo
    } else {
        State* s = arr[front];
        if (number_elements() == 1) {
            front = back = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return s;
    }
}

void Queue::push(State* s) {
    if (number_elements() == size) { // queremos que esta estructura sea auto incrementable
        resize();
    }

    if (number_elements() == 0) { // si la cola está vacía
        front = back = 0;
    } else if (back == size - 1) { // si el último está al final del arreglo
        back = 0;
    } else {
        back = (back + 1) % size;
    }
    arr[back] = s;
}

bool Queue::find(State* s) {
    if (front == -1 && back == -1) {
        return false;
    }
    if (back >= front) {
        for (int k = front; k <= back; k++) {
            if (arr[k]->isGoal(s->bidones)) {
                return true;
            }
        }
    } else {
        for (int k = front; k <= size - 1; k++) {
            if (arr[k]->isGoal(s->bidones)) {
                return true;
            }
        }
        for (int k = 0; k <= back; k++) {
            if (arr[k]->isGoal(s->bidones)) {
                return true;
            }
        }
    }
    return false;
}

void Queue::resize() {
    int newSize = size * 2;
    State** newArr = new State*[newSize];
    if (back >= front) {
        for (int i = front; i <= back; ++i) {
            newArr[i - front] = arr[i];
        }
    } else {
        int index = 0;
        for (int i = front; i < size; ++i) {
            newArr[index++] = arr[i];
        }
        for (int i = 0; i <= back; ++i) {
            newArr[index++] = arr[i];
        }
    }
    front = 0;
    back = number_elements() - 1;
    size = newSize;
    delete[] arr;
    arr = newArr;
}