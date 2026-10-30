#include "DirectEvaluate.hpp"

template <typename T> SqStack<T>::SqStack() { top = 0; }

template <typename T> Status SqStack<T>::Push(const T &e) {
  if (StackFull() == OK) {
    return ERROR;
  }
  data[top] = e;
  top++;
  return OK;
}

template <typename T> Status SqStack<T>::Pop(T &e) {
  if (StackEmpty() == OK) {
    return ERROR;
  }
  top--;
  e = data[top];
  return OK;
}

template <typename T> Status SqStack<T>::GetTop(T &e) const {
  if (StackEmpty() == OK) {
    return ERROR;
  }
  e = data[top - 1];
  return OK;
}

template <typename T> Status SqStack<T>::ClearStack() {
  top = 0;
  return OK;
}

template <typename T> Status SqStack<T>::StackEmpty() const {
  if (top == 0) {
    return OK;
  }
  return ERROR;
}

template <typename T> Status SqStack<T>::StackFull() const {
  if (top == MAXSIZE) {
    return OK;
  }
  return ERROR;
}

template class SqStack<char>;
template class SqStack<int>;

int isp(char op) {
  switch (op) {
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
    return 4;
  case '(':
  case '#':
    return 0;
  default:
    return -1;
  }
}

int icp(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 3;
  case '(':
    return 5;
  case ')':
  case '#':
    return 0;
  default:
    return -1;
  }
}

char Compare(char top, char c) {
  int inPriority = isp(top);
  int outPriority = icp(c);
  if (inPriority < outPriority) {
    return '<';
  }
  if (inPriority > outPriority) {
    return '>';
  }
  return '=';
}

Status Evaluate(const string &infix, int &result) {
  string expression = infix + '#';
  SqStack<int> OPND;
  SqStack<char> OPTR;
  OPTR.Push('#');
  int i = 0;
  while (true) {
    char c = expression[i];
    if (c >= '0' && c <= '9') {
      OPND.Push(c - '0');
      i++;
      continue;
    }
    char top;
    OPTR.GetTop(top);
    char relation = Compare(top, c);
    if (relation == '<') {
      OPTR.Push(c);
      i++;
    } else if (relation == '>') {
      char op;
      OPTR.Pop(op);
      int left, right;
      OPND.Pop(right);
      OPND.Pop(left);

      int r;
      if (op == '+') {
        r = left + right;
      } else if (op == '-') {
        r = left - right;
      } else if (op == '*') {
        r = left * right;
      } else {
        r = left / right;
      }
      OPND.Push(r);
    } else {
      OPTR.Pop(top);
      if (c == '#') {
        break;
      }
      i++;
    }
  }
  OPND.Pop(result);
  return OK;
}