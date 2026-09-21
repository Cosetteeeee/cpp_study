#include "SeqList.h"
#include <iostream>

Status InitList(SqList &L) {
  L.elem = new ElemType[MAXSIZE];
  if (!L.elem)
    exit(OVERFLOW);
  L.length = 0;
  return OK;
}

Status DestroyList(SqList &L) {
  if (L.elem) {
    delete[] L.elem;
  }
  L.elem = NULL;
  L.length = 0;
  return OK;
}

Status ClearList(SqList &L) {
  L.length = 0;
  return OK;
}

Status ListTraverse(const SqList &L) {
  if (L.length == 0) {
    cout << endl;
    return OK;
  }
  ElemType *p = L.elem;
  for (; p <= L.elem + L.length - 1; p++) {
    cout << *p << " ";
  }
  cout << endl;
  return OK;
}

Status GetElem(const SqList &L, int i, ElemType &e) {
  if (i < 1 || i > L.length) {
    return ERROR;
  }
  e = L.elem[i - 1];
  return OK;
}

int LocateElem(const SqList &L, ElemType e) {
  for (int i = 0; i < L.length; i++) {
    if (L.elem[i] == e) {
      return i + 1;
    }
  }
  return 0;
}

Status ListInsert(SqList &L, int i, ElemType e) {
  if (L.length >= MAXSIZE) {
    return ERROR;
  }
  if (i < 1 || i > L.length + 1) {
    return ERROR;
  }
  for (int j = L.length - 1; j >= i - 1; j--) {
    L.elem[j + 1] = L.elem[j];
  }
  L.elem[i - 1] = e;
  L.length++;
  return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e) {
  if (L.length == 0) {
    return ERROR;
  }
  if (i < 1 || i > L.length) {
    return ERROR;
  }
  e = L.elem[i - 1];
  for (int j = i - 1; j < L.length - 1; j++) {
    L.elem[j] = L.elem[j + 1];
  }
  L.length--;
  return OK;
}

int ListLength(const SqList &L) { return L.length; }

Status ListEmpty(const SqList &L) {
  if (L.length) {
    return ERROR;
  }
  return OK;
}