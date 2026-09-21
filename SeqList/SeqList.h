#pragma once
#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

typedef struct {
  ElemType *elem;
  int length;
} SqList;

Status InitList(SqList &L);
Status DestroyList(SqList &L);
Status ClearList(SqList &L);
Status ListTraverse(const SqList &L);
Status GetElem(const SqList &L, int i, ElemType &e);
int LocateElem(const SqList &L, ElemType e);
Status ListInsert(SqList &L, int i, ElemType e);
Status ListDelete(SqList &L, int i, ElemType &e);
int ListLength(const SqList &L);
Status ListEmpty(const SqList &L);