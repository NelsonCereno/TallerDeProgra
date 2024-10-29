#include "Jug.h"

int main() {
  Jug j(1000,1000);
  State *solution = j.solve();
  solution->print();
  return 0;
}