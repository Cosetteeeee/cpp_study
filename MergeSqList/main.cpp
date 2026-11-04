#include "SqList.h"

int main() {
  SqList A;
  SqList B;
  SqList C;

  if (InitList(A) != OK) {
    cout << "顺序表 A 初始化失败。" << endl;
    return 0;
  }
  if (InitList(B) != OK) {
    cout << "顺序表 B 初始化失败。" << endl;
    DestroyList(A);
    return 0;
  }
  if (InitList(C) != OK) {
    cout << "顺序表 C 初始化失败。" << endl;
    DestroyList(A);
    DestroyList(B);
    return 0;
  }

  // 有序表 A = (3, 5, 8, 11)
  ListInsert(A, A.length + 1, 3);
  ListInsert(A, A.length + 1, 5);
  ListInsert(A, A.length + 1, 8);
  ListInsert(A, A.length + 1, 11);

  // 有序表 B = (2, 6, 8, 9, 11, 15, 20)
  ListInsert(B, B.length + 1, 2);
  ListInsert(B, B.length + 1, 6);
  ListInsert(B, B.length + 1, 8);
  ListInsert(B, B.length + 1, 9);
  ListInsert(B, B.length + 1, 11);
  ListInsert(B, B.length + 1, 15);
  ListInsert(B, B.length + 1, 20);

  cout << "A = ";
  ListTraverse(A);

  cout << "B = ";
  ListTraverse(B);

  if (MergeList_Sq(A, B, C) != OK) {
    cout << "合并失败。" << endl;
    DestroyList(A);
    DestroyList(B);
    DestroyList(C);
    return 0;
  }

  cout << "C = A并B，合并后：" << endl;
  cout << "C = ";
  ListTraverse(C);

  DestroyList(A);
  DestroyList(B);
  DestroyList(C);
  return 0;
}
