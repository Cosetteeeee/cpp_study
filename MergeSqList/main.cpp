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

  int n;
  int m;
  ElemType e;

  cout << "请输入有序表 A 的元素个数：";
  cin >> n;
  cout << "请一次性按升序输入 A 的 " << n << " 个元素：";
  for (int i = 0; i < n; i++) {
    cin >> e;
    ListInsert(A, A.length + 1, e);
  }

  cout << "请输入有序表 B 的元素个数：";
  cin >> m;
  cout << "请一次性按升序输入 B 的 " << m << " 个元素：";
  for (int i = 0; i < m; i++) {
    cin >> e;
    ListInsert(B, B.length + 1, e);
  }

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
