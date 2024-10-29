#include "Queue.h"

Queue::Queue(){
    arr=nullptr;
    front=-1;
    back=-1;
    size=-1;
}

Queue::Queue(int n){
    arr=new State*[n]; // un arreglo de n elementos de tipo State*
    size=n;
    front=-1; // definimos que una cola vacia es back=fron=-1
    back=-1; // otra convencion es que el push lo hacemos en back+1
}

int Queue::number_elements(){
    if (back==-1 && front==-1) {
        return(0);
    }
    if (back >= front) {
        return (back-front+1);
    } else {
        return(size-front+back+1);
    }
}

State* Queue::pop() {
    if (number_elements()==0 ) { // si la cola esta vacia
        return(nullptr); // Si la cola esta vacia retornamos nulo
    } else {
        State* s= arr[front];
        if (number_elements()==1) {
            front=back=-1;
        } else if (front == size-1) {
            front=0;
        } else {
            front++; 
        }
        
        return (s);
    }
}

void Queue::push(State* s){
    if(number_elements()==size) { // queremos que esta estructura sea auto incrementable
        State** arr_tmp = new State* [2*size];
        // copiamos el arreglo antiguo aqui
        if (back>=front) { // copiar entre medio de ambos
            for(int k=front; k<=back; k++) {
              arr_tmp[k-front] = arr[k];
            }
        } else {
            for (int k=front; k<=size-1; k++) {
              arr_tmp[k-front] = arr[k];
            }
            for(int k=0; k<=back; k++) {
              arr_tmp[k+size-front] = arr[k];
            }

        }
        front=0;
        back=size-1;
        size=size*2;
        delete[] arr; // esto es igual que free de C
        arr=arr_tmp;
    }  
    // aqui ya corregimos cualquier falta de memoria ocurra

    if (number_elements()==0) { // si la cola esta vacia
            front=back=0;
    } else if(back == size-1) { // si el ultimo esta al final del arreglo
            back=0;
    } else {
            back = (back+1)%size;
    }
    arr[back]=s; 
    
    return;
}

bool Queue::find(State* s) {
    if (front==-1 && back==-1) {
        return (false);
    }
    if (back>=front) {
        for(int k=front; k<=back; k++){
            if(arr[k]->a0==s->a0 && arr[k]->a1==s->a1) {
                return true;
            }
        }
    } else {
        for(int k=front; k<=size-1; k++){
            if(arr[k]->a0==s->a0 && arr[k]->a1==s->a1) {
                return true;
            }
        }
        for(int k=0; k<=back; k++) {
            if(arr[k]->a0==s->a0 && arr[k]->a1==s->a1) {
                return true;
            }
        }
    }
    return (false);
}
