#pragma once
#include <iostream>
using namespace std;

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef char SElemType;
typedef int Status;

typedef struct SNode {
    SElemType data;
    struct SNode* next;
} SNode, *LinkStack;

void InitStack(LinkStack& S);
Status Push(LinkStack& S, SElemType e);
Status Pop(LinkStack& S, SElemType& e);
Status GetTop(LinkStack& S, SElemType& e);
Status Traverse(const LinkStack& S);
Status ClearStack(LinkStack& S);
Status DestroyStack(LinkStack& S);
Status StackEmpty(LinkStack S);

Status BracketMatch(const char expression[]);