#include "SqList.h"

int main() {
  SqList A;
  SqList B;

  if (InitList(A) != OK) {
    cout << "顺序表 A 初始化失败。" << endl;
    return 0;
  }
  if (InitList(B) != OK) {
    cout << "顺序表 B 初始化失败。" << endl;
    DestroyList(A);
    return 0;
  }

  // A = (7, 5, 3, 11)
  ListInsert(A, 1, 7);
  ListInsert(A, 2, 5);
  ListInsert(A, 3, 3);
  ListInsert(A, 4, 11);

  // B = (2, 6, 3)
  ListInsert(B, 1, 2);
  ListInsert(B, 2, 6);
  ListInsert(B, 3, 3);

  cout << "创建顺序表 A 和 B：" << endl;
  cout << "A = ";
  ListTraverse(A);
  cout << "B = ";
  ListTraverse(B);

  if (Union(A, B) != OK) {
    cout << "合并失败。" << endl;
    DestroyList(A);
    DestroyList(B);
    return 0;
  }

  cout << "合并后：" << endl;
  cout << "A = ";
  ListTraverse(A);

  DestroyList(A);
  DestroyList(B);
  return 0;
}
