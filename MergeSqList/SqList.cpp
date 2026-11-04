#include "SqList.h"

Status InitList(SqList &L) {
  L.elem = new ElemType[MAXSIZE];
  L.length = 0;
  return OK;
}

Status DestroyList(SqList &L) {
  if (L.elem != nullptr) {
    delete[] L.elem;
  }
  L.elem = nullptr;
  L.length = 0;
  return OK;
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

void ListTraverse(const SqList &L) {
  cout << "(";
  for (int i = 0; i < L.length; i++) {
    if (i > 0) {
      cout << ", ";
    }
    cout << L.elem[i];
  }
  cout << ")" << endl;
}

Status MergeList_Sq(const SqList &La, const SqList &Lb, SqList &Lc) {
  if (La.length + Lb.length > MAXSIZE) {
    return ERROR;
  }

  int i = 1;
  int j = 1;
  int k = 1;

  while (i <= La.length && j <= Lb.length) {
    if (La.elem[i - 1] <= Lb.elem[j - 1]) {
      Lc.elem[k - 1] = La.elem[i - 1];
      i++;
    } else {
      Lc.elem[k - 1] = Lb.elem[j - 1];
      j++;
    }
    k++;
  }

  while (i <= La.length) {
    Lc.elem[k - 1] = La.elem[i - 1];
    i++;
    k++;
  }

  while (j <= Lb.length) {
    Lc.elem[k - 1] = Lb.elem[j - 1];
    j++;
    k++;
  }

  Lc.length = k - 1;
  return OK;
}
