#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0
typedef int Status;
template <typename T>

class SqStack {
  T data[MAXSIZE];
  int top;

public:
  SqStack();
  Status Push(const T &e);
  Status Pop(T &e);
  Status GetTop(T &e) const;
  Status ClearStack();
  Status StackEmpty() const;
  Status StackFull() const;
};

Status Evaluate(const string& infix, int& result);