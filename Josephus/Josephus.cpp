#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

typedef Node *LinkList;

/*
  约瑟夫环示意（n = 8，m = 3，从 1 号开始报数）：

  初始环：
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ^                                      |
    +--------------------------------------+

  第一次报数到 3：
    prev  cur
     2     3

  删除 3 号后：
    1 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8 -> 1
         prev  cur

  下一次从 4 号重新报 1。prev 始终指向 cur 的前一个结点，
  因此删除 cur 时可以直接执行 prev->next = cur->next。
*/

// 创建不含头结点的循环链表，结点编号为 1 到 n。
LinkList CreateCircle(int n) {
  if (n <= 0) {
    return nullptr;
  }

  Node *head = new Node;
  head->data = 1;
  head->next = head;

  Node *tail = head;

  for (int i = 2; i <= n; i++) {
    Node *p = new Node;
    p->data = i;
    p->next = head;
    tail->next = p;
    tail = p;
  }

  return head;
}

// 遍历循环链表，最后再次输出头结点，表示链表是环形的。
void Traverse(LinkList head) {
  if (head == nullptr) {
    cout << "空链表" << endl;
    return;
  }

  Node *p = head;
  do {
    cout << p->data;
    p = p->next;
    if (p != head) {
      cout << " -> ";
    }
  } while (p != head);

  cout << " -> " << head->data << endl;
}

// 按报数上限 m 依次删除结点，打印出环顺序和最后剩下的结点。
void Josephus(LinkList head, int m) {
  if (head == nullptr) {
    return;
  }

  Node *prev = head;
  while (prev->next != head) {
    prev = prev->next;
  }

  Node *cur = head;

  cout << "自杀顺序：";

  // 当 cur 的 next 指向自己时，只剩下最后一个人。
  while (cur->next != cur) {
    // 从 cur 开始报 1，报到 m 时 cur 就是要删除的结点。
    for (int i = 1; i < m; i++) {
      prev = cur;
      cur = cur->next;
    }

    cout << cur->data << " ";

    // cur 是待删除结点，prev 是它的前驱。
    prev->next = cur->next;
    delete cur;
    cur = prev->next;
  }

  cout << endl;
  cout << "最后的约瑟夫是：" << cur->data << endl;

  delete cur;
}

int main() {
  int n;
  int m;

  cout << "请输入人数和报数上限：";
  cin >> n >> m;

  if (n <= 0 || m <= 0) {
    cout << "人数和报数上限都必须是正整数。" << endl;
    return 0;
  }

  LinkList head = CreateCircle(n);

  cout << "循环链表：";
  Traverse(head);

  Josephus(head, m);

  return 0;
}
