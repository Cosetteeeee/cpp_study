#include "Polynomial.h"

int main() {
  Polynomial A;
  Polynomial B;
  Polynomial C;
  Polynomial D;
  Polynomial E;
  Polynomial R;

  CreatePolyn(A, 4);
  orderInsert(B, 3);
  Traverse(A);
  Traverse(B);
  Add(A, B, R);
  Traverse(R);

  CreatePolyn(C, 3);
  orderInsert(D, 2);
  Traverse(C);
  Traverse(D);
  Sub(C, D, R);
  Traverse(R);

  orderInsert(E, 4);
  Traverse(E);
  cout<<Evaluate(E, 2)<<endl;

  return 0;
}