#pragma once

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct {
  ElemType *elem;
  int length;
} SqList;

Status InitList(SqList &L);
Status DestroyList(SqList &L);
Status ListInsert(SqList &L, int i, ElemType e);
void ListTraverse(const SqList &L);
Status MergeList_Sq(const SqList &La, const SqList &Lb, SqList &Lc);
