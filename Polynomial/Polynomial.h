#pragma once
#include <iostream>
using namespace std;

typedef struct Term {
  double coef;
  int expn;
} Term;

typedef struct PNode {
  Term data;
  PNode *next;
} *Polynomial;

void CreatePolyn(Polynomial &L, int n);
void orderInsert(Polynomial &L, int n);
void Traverse(const Polynomial &L);
void Reverse(Polynomial &L);
void Add(Polynomial &A, Polynomial &B, Polynomial &C);
void Sub(Polynomial &A, Polynomial &B, Polynomial &C);
double Evaluate(const Polynomial &L, double x);