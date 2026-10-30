#include "Convert.hpp"
#include <cstdlib>

void InitStack(LinkStack &S) { S = nullptr; }

Status StackEmpty(LinkStack S) { return S == nullptr; }

Status Push(LinkStack &S, OPTRType e) {
  OPTR *p = new OPTR;
  if (!p) {
    exit(OVERFLOW);
  }
  p->data = e;
  p->next = S;
  S = p;
  return OK;
}

Status Pop(LinkStack &S, OPTRType &e) {
  if (StackEmpty(S)) {
    return ERROR;
  }
  OPTR *p = S;
  e = S->data;
  S = S->next;
  delete p;
  return OK;
}

Status GetTop(LinkStack &S, OPTRType &e) {
  if (StackEmpty(S)) {
    return ERROR;
  }
  e = S->data;
  return OK;
}

Status Traverse(const LinkStack &S) {
  OPTR *p = S;
  while (p) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
  return OK;
}

Status ClearStack(LinkStack &S) {
  OPTR *p;
  while (S) {
    p = S;
    S = S->next;
    delete p;
  }
  return OK;
}

Status DestroyStack(LinkStack &S) { return ClearStack(S); }

namespace {
bool IsOpening(char ch) { return ch == '(' || ch == '[' || ch == '{'; }

bool IsClosing(char ch) { return ch == ')' || ch == ']' || ch == '}'; }

char ExpectedClosing(char opening) {
  switch (opening) {
  case '(':
    return ')';
  case '[':
    return ']';
  case '{':
    return '}';
  default:
    return '\0';
  }
}
}
