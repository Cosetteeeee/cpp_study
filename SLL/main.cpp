#include "SLL.h"

int main() {
  LinkList L;
  InitList(L);

  cout << "单链表初始化成功\n";
  cout << "空表：ListEmpty = " << ListEmpty(L)
       << "，ListLength = " << ListLength(L) << "\n";

  string id;
  cout << "请输入你的姓名缩写+学号，例如张三 20251234->'zs20251234'：";
  cin >> id;
  CreateList_R(L, id);

  cout << "尾插创建链表：";
  ListTraverse(L);

  cout << "非空：ListEmpty = " << ListEmpty(L)
       << "，ListLength = " << ListLength(L) << "\n";

  ElemType e;
  for (int i = 0; i < 3; i++) {
    int num;
    cout << "第" << i + 1 << "/3次输入你想要查找的位序：";
    cin >> num;
    if (num < 1 || num > ListLength(L)) {
      cout << "查找不成功，合法位序为1~" << ListLength(L) << "\n";
    } else {
      GetElem(L, num, e);
      cout << "该元素是：" << (char)e << "\n";
    }
  }

  for (int i = 0; i < 3; i++) {
    string str;
    cout << "第" << i + 1 << "/3次输入你想要查找的元素（单个字符）：";
    cin >> str;
    if (str.length() != 1) {
      cout << "查找不成功，请输入单个字符\n";
    } else {
      int pos = LocateElem(L, str[0]);
      if (pos == 0) {
        cout << "链表中没有该元素\n";
      } else {
        cout << "该元素的位序是：" << pos << "\n";
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    int num;
    string str;
    cout << "第" << i + 1 << "/2次输入插入位序和元素（如3 a）：";
    cin >> num >> str;
    if (str.length() != 1 || ListInsert(L, num, str[0]) == ERROR) {
      cout << "插入不成功，合法位序为1~" << ListLength(L) + 1 << "\n";
    } else {
      cout << "成功插入，当前链表：";
      ListTraverse(L);
    }
  }

  for (int i = 0; i < 2; i++) {
    int num;
    cout << "第" << i + 1 << "/2次输入删除位序：";
    cin >> num;
    if (ListDelete(L, num, e) == ERROR) {
      cout << "删除不成功，合法位序为1~" << ListLength(L) << "\n";
    } else {
      cout << "成功删除元素" << (char)e << "，当前链表：";
      ListTraverse(L);
    }
  }

  for (int i = 0; i < 2; i++) {
    string str;
    cout << "第" << i + 1 << "/2次输入你想要查找的元素（Find）：";
    cin >> str;
    LNode *p = (str.length() == 1) ? LinkListFind(L, str[0]) : nullptr;
    if (p == nullptr) {
      cout << "未找到该元素\n";
    } else {
      cout << "找到结点，返回指针 " << p << "\n";
    }
  }

  for (int i = 0; i < 2; i++) {
    int num;
    cout << "第" << i + 1 << "/2次输入要查找的位序（Locate）：";
    cin >> num;
    LNode *p = LinkListLocate(L, num);
    if (p == nullptr) {
      cout << "查找不成功，合法位序为1~" << ListLength(L) << "\n";
    } else {
      cout << "找到结点，返回指针 " << p << "\n";
    }
  }

  ClearList(L);
  cout << "置空：ListEmpty = " << ListEmpty(L)
       << "，ListLength = " << ListLength(L) << "\n";
  string str;
  cout << "输入一个字符验证置空后仍可插入：";
  cin >> str;
  if (str.length() == 1 && ListInsert(L, 1, str[0]) == OK) {
    cout << "成功插入，当前链表：";
    ListTraverse(L);
  }

  ClearList(L);
  CreateList_H(L, id);
  cout << "头插创建链表：";
  ListTraverse(L);

  DestroyList(L);
  cout << (L == nullptr ? "链表已销毁\n" : "销毁异常\n");

  return 0;
}