#include "LinkStack.h"
#include <cstdlib>

void InitStack(LinkStack &S) { S = nullptr; }

Status StackEmpty(LinkStack S) { return S == nullptr; }

Status Push(LinkStack &S, SElemType e) {
  SNode *p = new SNode;
  if (!p) {
    exit(OVERFLOW);
  }
  p->data = e;
  p->next = S;
  S = p;
  return OK;
}

Status Pop(LinkStack &S, SElemType &e) {
  if (StackEmpty(S)) {
    return ERROR;
  }
  SNode *p = S;
  e = S->data;
  S = S->next;
  delete p;
  return OK;
}

Status GetTop(LinkStack &S, SElemType &e) {
  if (StackEmpty(S)) {
    return ERROR;
  }
  e = S->data;
  return OK;
}

Status Traverse(const LinkStack &S) {
  SNode *p = S;
  while (p) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
  return OK;
}

Status ClearStack(LinkStack &S) {
  SNode *p;
  while (S) {
    p = S;
    S = S->next;
    delete p;
  }
  return OK;
}

Status DestroyStack(LinkStack &S) { return ClearStack(S); }
