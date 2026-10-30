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

Status BracketMatch(const char expression[]) {
  LinkStack S;
  InitStack(S);

  int i = 0;
  while (expression[i] != '\0' && expression[i] != '#') {
    const char ch = expression[i];

    if (IsOpening(ch)) {
      if (Push(S, ch) != OK) {
        DestroyStack(S);
        return ERROR;
      }
    } else if (IsClosing(ch)) {
      if (StackEmpty(S) == OK) {
        DestroyStack(S);
        return ERROR;
      }

      SElemType top;
      GetTop(S, top);
      const char expected = ExpectedClosing(top);
      if (ch != expected) {
        DestroyStack(S);
        return ERROR;
      }
      Pop(S, top);
    }
    ++i;
  }

  if (StackEmpty(S) == ERROR) {
    DestroyStack(S);
    return ERROR;
  }

  DestroyStack(S);
  return OK;
}

