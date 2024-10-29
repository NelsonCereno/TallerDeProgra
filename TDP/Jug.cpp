#include "Jug.h"

Jug::Jug(int a, int b) {
  open = new Queue(a);
  all = new Queue(b);
  State *s = new State(0,0,nullptr,"");
  open->push(s);
  all->push(s);
}

State* Jug::fill0(State* o) {
  if (o->a0<3) {
    State *s = new State(3,o->a1,o,"fill0");
    return(s);
  } else {
    return(nullptr);
  }
}

State* Jug::fill1(State* o) {
  if (o->a1<5) {
    State *s = new State(o->a0,5,o,"fill1");
    return(s);
  } else {
    return(nullptr);
  }
}

State* Jug::empty0(State* o) {
  if (o->a0>0) {
    State *s = new State(0,o->a1,o,"empty0");
    return(s);
  } else {
    return(nullptr);
  }
}

State* Jug::empty1(State* o) {
  if (o->a1>0) {
    State *s = new State(o->a0,0,o,"empty1");
    return(s);
  } else {
    return(nullptr);
  }
}

State* Jug::transfer01(State* o) {
  if (o->a0>0 && o->a1<5) {
    int t = 5-o->a1;
    if (o->a0>t) {
      State *s = new State(o->a0-t,5,o,"transfer01");
      return(s);
    } else {
      State *s = new State(0,o->a1+o->a0,o,"transfer01");
      return(s);
    }
  } else {
    return(nullptr);
  }
}

State* Jug::transfer10(State* o) {
  if (o->a1>0 && o->a0<3) {
    int t = 3-o->a0;
    if (o->a1>t) {
      State *s = new State(3,o->a1-t,o,"transfer10");
      return(s);
    } else {
      State *s = new State(o->a0+o->a1,0,o,"transfer10");
      return(s);
    }
  } else {
    return(nullptr);
  }
}

State* Jug::solve() {
  while (open->number_elements()>0) { // mientras la cola open no este vacia
    State *s = open->pop(); // AQUI deberia sacar el mejor elemento

    if (s->a1==4) {
      return(s);
    }

    // esto nunca se deberia hacer!!!
    State *f0 = fill0(s);
    State *f1 = fill1(s);
    State *e0 = empty0(s);
    State *e1 = empty1(s);
    State *t01 = transfer01(s);
    State *t10 = transfer10(s);
    if (f0!=nullptr && !all->find(f0)) {
        open->push(f0);
        all->push(f0);
    } else if (f0!=nullptr) { // si ya existe, lo borro
        delete(f0);
    }
    if (f1!=nullptr && !all->find(f1)) {
        open->push(f1);
        all->push(f1);
    } else if (f1!=nullptr) { // si ya existe, lo borro
        delete(f1);
    }
    if (e0!=nullptr && !all->find(e0)) {
        open->push(e0);
        all->push(e0);
    } else if (e0!=nullptr) { // si ya existe, lo borro
        delete(e0);
    }
    if (e1!=nullptr && !all->find(e1)) {
        open->push(e1);
        all->push(e1);
    } else if (e1!=nullptr) { // si ya existe, lo borro
        delete(e1);
    }
    if (t01!=nullptr && !all->find(t01)) {
        open->push(t01);
        all->push(t01);
    } else if (t01!=nullptr) { // si ya existe, lo borro
        delete(t01);
    }
    if (t10!=nullptr && !all->find(t10)) {
        open->push(t10);
        all->push(t10);
    } else if (t10!=nullptr) { // si ya existe, lo borro
        delete(t10);
    }
  }
  return(nullptr);
}