#pragma once
#include <iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef char OPTRType;
typedef int Status;

typedef struct OPTR {
    OPTRType data;
    struct OPTR* next;
} OPTR, *LinkStack;

void InitStack(LinkStack& S);
Status Push(LinkStack& S, OPTRType e);
Status Pop(LinkStack& S, OPTRType& e);
Status GetTop(LinkStack& S, OPTRType& e);
Status Traverse(const LinkStack& S);
Status ClearStack(LinkStack& S);
Status DestroyStack(LinkStack& S);
Status StackEmpty(LinkStack S);
