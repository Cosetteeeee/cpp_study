#include "SLL.h"

Status InitList(LinkList &L) {
  L = new LNode;
  L->next = nullptr;
  return OK;
}

void CreateList_H(LinkList &L, const string &str) {
  for (char ch : str) {
    LNode *p = new LNode;
    p->data = ch;
    p->next = L->next;
    L->next = p;
  }
}

void CreateList_R(LinkList &L, const string &str) {
  LNode *r = L;
  for (char ch : str) {
    LNode *p = new LNode;
    p->data = ch;
    p->next = nullptr;
    r->next = p;
    r = p;
  }
}

Status ListTraverse(const LinkList &L) {
  LNode *p = L->next;
  while (p) {
    cout << (char)p->data << " ";
    p = p->next;
  }
  cout << "\n";
  return OK;
}

Status GetElem(const LinkList &L, int i, ElemType &e) {
  LNode *p = L->next;
  int j = 1;
  while (p && j < i) {
    p = p->next;
    j++;
  }
  if (!p || j > i) {
    return ERROR;
  }
  e = p->data;
  return OK;
}

int LocateElem(const LinkList &L, ElemType e) {
  LNode *p = L->next;
  int i = 1;
  while (p && p->data != e) {
    p = p->next;
    i++;
  }
  return p ? i : 0;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
  LNode *p = L;
  int j = 0;
  while (p && j < i - 1) {
    p = p->next;
    j++;
  }
  if (!p || j > i - 1) {
    return ERROR;
  }
  LNode *s = new LNode;
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e) {
  LNode *p = L;
  int j = 0;
  while (p && j < i - 1) {
    p = p->next;
    j++;
  }
  if (!p || !p->next || j > i - 1) {
    return ERROR;
  }
  e = p->next->data;
  LNode *q = p->next;
  p->next = q->next;
  delete q;
  return OK;
}

Status ListEmpty(const LinkList &L) {
  if (!L->next) {
    return OK;
  }
  return ERROR;
}

int ListLength(const LinkList &L) {
  LNode *p = L->next;
  int count = 0;
  while (p) {
    p = p->next;
    count++;
  }
  return count;
}

Status DestroyList(LinkList &L) {
  LNode *p;
  while (L) {
    p = L;
    L = L->next;
    delete p;
  }
  return OK;
}

Status ClearList(LinkList &L) {
  LNode *p = L->next;
  while (p) {
    LNode *q = p->next;
    delete p;
    p = q;
  }
  L->next = nullptr;
  return OK;
}

LNode *LinkListFind(const LinkList &L, ElemType e) {
  LNode *p = L->next;
  while (p && p->data != e) {
    p = p->next;
  }
  return p;
}

LNode *LinkListLocate(const LinkList &L, int i) {
  LNode *p = L->next;
  int j = 1;
  while (p && j < i) {
    p = p->next;
    j++;
  }
  if (!p || j > i) {
    return nullptr;
  }
  return p;
}