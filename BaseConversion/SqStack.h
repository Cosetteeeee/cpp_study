#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0
typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S);
Status Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
Status GetTop(SqStack& S, SElemType& e);
Status Traverse(SqStack& S);
Status ClearStack(SqStack& S);
Status DestroyStack(SqStack& S);
Status StackEmpty(SqStack& S);
Status StackFull(SqStack& S);
Status DecimalToBase(int N, int d);