// { dg-do assemble  }
#include <stdlib.h>

class A {
public:
  void z();
  A(void) {}
private:
  A(const A &) { abort(); } // { dg-error "" } 
  const A& operator =(const A &) { abort(); }
};

class B : public A {
public:
  B(void) {}
};

void f(B b) {
}

void g() {
  B h;
  f(h); // { dg-error "" } 
}
