#include "SeqList.h"
#include <iostream>

int main() {
  SqList L;
  InitList(L);
  for (int i = 1; i <= 5; i++) {
    ListInsert(L, 1, i);
  }
  ListTraverse(L);
  ListInsert(L, 6, 6);
  cout << "元素5 位序" << LocateElem(L, 5) << endl;
  cout << "元素6 位序" << LocateElem(L, 6) << endl;
  cout << "元素2 位序" << LocateElem(L, 2) << endl;
  for (int i = 7; i <= 11; i++) {
    ListInsert(L, 2, i);
  }
  ListTraverse(L);
  ElemType e;
  ListDelete(L, 1, e);
  cout << "删除的元素为" << e << endl;
  ListDelete(L, 1, e);
  cout << "删除的元素为" << e << endl;
  ListTraverse(L);
  ListDelete(L, 9, e);
  cout << "删除的元素为" << e << ",此时顺序表的长度为" << ListLength(L) << endl;
  ListTraverse(L);
  ClearList(L);
  cout << "此时顺序表的长度为" << ListLength(L) << endl;
  if (ListInsert(L, 2, 10)) {
    cout << "成功插入" << endl;
  } else {
    cout << "插入不成功" << endl;
  }
  for (int i = 1; i <= 5; i++) {
    ListInsert(L, L.length + 1, i);
  }
  ListTraverse(L);
  DestroyList(L);
  return 0;
}