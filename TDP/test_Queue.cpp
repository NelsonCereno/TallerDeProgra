#include "Queue.h"

int main() {
   Queue *q = new Queue(2);
   
    State *s = new State(0, 0, nullptr, "init");
    q->push(s);
    State *s1 = new State(3, 0, s, "fill a0");
    q->push(s1);
    State *s2 = new State(3, 5, s1, "fill a1");
    q->push(s2);
    State *s3 = new State(0, 5, s2, "pour a0"); 
    q->push(s3); 

    s3->print();
    cout << "Tamaño: " << q->number_elements() << endl;
    cout <<"front:"<< q->front<<" back:" << q->back << endl;
    cout <<"*************************"<<endl;
    State *ss;
    while (q->number_elements()>0) {
        cout << "number of element : " << q->number_elements()<<endl;
        ss = q->pop();
        cout <<"POP: front:"<< q->front<<" back:" << q->back << endl;
       if (ss != nullptr) { 
          cout << "a0:"<< ss->a0 << " a1:"<< ss->a1 << endl; 
        }
    }
    return(0);
}