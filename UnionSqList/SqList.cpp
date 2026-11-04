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

  for (int j = L.length; j >= i; j--) {
    L.elem[j] = L.elem[j - 1];
  }

  L.elem[i - 1] = e;
  L.length++;
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

int ListLength(const SqList &L) { return L.length; }

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

Status Union(SqList &La, const SqList &Lb) {
  int La_len = ListLength(La);
  int Lb_len = ListLength(Lb);
  ElemType e;

  for (int i = 1; i <= Lb_len; i++) {
    if (GetElem(Lb, i, e) != OK) {
      return ERROR;
    }

    if (LocateElem(La, e) == 0) {
      if (ListInsert(La, La_len + 1, e) != OK) {
        return ERROR;
      }
      La_len++;
    }
  }

  return OK;
}
