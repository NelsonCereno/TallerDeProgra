#include "A.h"


class C : public A {
  public:
  C(int a);
  int operate(int x); // sobre escribimos aqui
};