#include "Polynomial.h"
#include <cmath>

void CreatePolyn(Polynomial &L, int n) {
  PNode *r;
  L = r = new PNode;
  L->next = nullptr;
  for (int i = 0; i < n; i++) {
    PNode *s = new PNode;
    cin >> s->data.coef >> s->data.expn;
    s->next = r->next;
    r->next = s;
    r = s;
  }
}

void orderInsert(Polynomial &L, int n) {
  L = new PNode;
  L->next = nullptr;
  for (int i = 0; i < n; i++) {
    PNode *s = new PNode;
    cin >> s->data.coef >> s->data.expn;
    PNode *q = L;
    while (q->next && q->next->data.expn < s->data.expn) {
      q = q->next;
    }
    s->next = q->next;
    q->next = s;
  }
}

void Traverse(const Polynomial &L) {
  PNode *p = L->next;
  if (!p) {
    cout << "0" << endl;
    return;
  }
  bool first = true;
  while (p) {
    double c = p->data.coef;
    int e = p->data.expn;
    if (first) {
      if (c < 0) {
        cout << "-";
      }
    } else {
      cout << (c > 0 ? "+" : "-");
    }
    double a = fabs(c);
    if (!(a == 1 && e != 0)) {
      cout << a;
    }
    if (e == 1) {
      cout << "x";
    } else if (e != 0) {
      cout << "x^" << e;
    }
    first = false;
    p = p->next;
  }
  cout << endl;
}

void Reverse(Polynomial &L) {
  PNode *p = L->next;
  PNode *q;
  L->next = nullptr;
  while (p) {
    q = p;
    p = p->next;
    q->next = L->next;
    L->next = q;
  }
}

void Add(Polynomial &A, Polynomial &B, Polynomial &C) {
  PNode *pa, *pb, *pc;
  C = pc = A;
  pa = A->next;
  pb = B->next;
  delete B;
  while (pa && pb) {
    if (pa->data.expn == pb->data.expn) {
      pa->data.coef = pa->data.coef + pb->data.coef;
      PNode *p = pb;
      pb = pb->next;
      delete p;
      if (pa->data.coef) {
        pc->next = pa;
        pc = pa;
        pa = pa->next;
      } else {
        PNode *p = pa;
        pa = pa->next;
        delete p;
      }
    } else if (pa->data.expn < pb->data.expn) {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    } else {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  pc->next = pa ? pa : pb;
}

void Sub(Polynomial &A, Polynomial &B, Polynomial &C) {
  for (PNode *p = B->next; p; p = p->next) {
    p->data.coef = -p->data.coef;
  }
  Add(A, B, C);
}

double Evaluate(const Polynomial &L, double x) {
  double res = 0;
  PNode *p = L->next;
  if (p) {
    res = p->data.coef;
  }
  while (p) {
    if (p->next) {
      res =
          res * pow(x, p->data.expn - p->next->data.expn) + p->next->data.coef;
    } else {
      res = res * pow(x, p->data.expn);
    }
    p = p->next;
  }
  return res;
}