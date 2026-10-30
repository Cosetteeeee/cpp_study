#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW 0
typedef int OPNDType;
typedef int Status;

typedef struct OPND {
	OPNDType* base;
	OPNDType* top;
	int stacksize;
}OPND;

Status InitStack(OPND& S);
Status Push(OPND& S, OPNDType e);
Status Pop(OPND& S, OPNDType& e);
Status GetTop(OPND& S, OPNDType& e);
Status Traverse(OPND& S);
Status ClearStack(OPND& S);
Status DestroyStack(OPND& S);
Status StackEmpty(OPND& S);
Status StackFull(OPND& S);