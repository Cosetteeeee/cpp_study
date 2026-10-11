#pragma once
#include <iostream>
#include <string>
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList &L);
void CreateList_H(LinkList &L, const string &str);
void CreateList_R(LinkList &L, const string &str);
Status ListTraverse(const LinkList &L);
Status GetElem(const LinkList &L, int i, ElemType &e);
int LocateElem(const LinkList &L, ElemType e);
Status ListInsert(LinkList &L, int i, ElemType e);
Status ListDelete(LinkList &L, int i, ElemType &e);
Status ListEmpty(const LinkList &L);
int ListLength(const LinkList &L);
Status DestroyList(LinkList &L);
Status ClearList(LinkList &L);
LNode *LinkListFind(const LinkList &L, ElemType e);
LNode *LinkListLocate(const LinkList &L, int i);