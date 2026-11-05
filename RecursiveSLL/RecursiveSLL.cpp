#include <cstddef>
#include <iostream>
#include <new>
using namespace std;

typedef struct LNode {
  int data;
  LNode *next;
} LNode, *LinkList;

LinkList CreateList() {
  int x;
  cin >> x;
  if (x < 0) {
    return nullptr;
  }
  LNode *p = new LNode;
  p->data = x;
  p->next = CreateList();
  return p;
}

void PrintForward(const LinkList &L) {
  if (L == nullptr) {
    return;
  }
  cout << L->data << " ";
  PrintForward(L->next);
}

void PrintBackward(const LinkList &L) {
  if (L == nullptr) {
    return;
  }
  PrintBackward(L->next);
  cout << L->data << " ";
}

bool GetMax(LinkList L, int &maxValue) {
  if (L == nullptr) {
    return false;
  } else if (L->next == nullptr) {
    maxValue = L->data;
    return true;
  } else if (GetMax(L->next, maxValue) == false) {
    return false;
  }
  if (L->data > maxValue) {
    maxValue = L->data;
  }
  return true;
}

int CountNodes(LinkList L) {
  if (L == nullptr) {
    return 0;
  }
  return 1 + CountNodes(L->next);
}

int SumNodes(LinkList L) {
  if (L == nullptr) {
    return 0;
  }
  return L->data + SumNodes(L->next);
}

double Average(LinkList L) {
  double count = CountNodes(L);
  if (count == 0) {
    return 0;
  }
  double sum = SumNodes(L);
  return sum / count;
}

void DestroyList(LinkList &L) {
  if (L == nullptr) {
    return;
  }
  DestroyList(L->next);
  delete L;
  L = nullptr;
}

int main() {
  LinkList L = CreateList();
  cout << "正序打印：";
  PrintForward(L);
  cout << endl;
  cout << "逆序打印：";
  PrintBackward(L);
  cout << endl;
  int maxValue;
  if (GetMax(L, maxValue)) {
    cout << "最大值是：" << maxValue << endl;
  } else {
    cout << "是空链表" << endl;
  }
  int count = CountNodes(L);
  cout << "元素个数是：" << count << endl;
  double avg = Average(L);
  cout << "平均值是：" << avg << endl;
  return 0;
}