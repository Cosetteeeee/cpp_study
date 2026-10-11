#include <iostream>
using namespace std;

typedef struct LNode {
  int data;
  struct LNode *next;
} LNode, *LinkList;

int main() {
  LinkList L, r;
  L = new LNode;
  L->data = 1;
  L->next = L;
  r = L;
  int n, num;
  cin >> n >> num;
  for (int i = 2; i <= n; i++) {
    LinkList s = new LNode;
    s->data = i;
    s->next = r->next;
    r->next = s;
    r = s;
  }
  while (L->next != L) {
    for (int i = 0; i < num - 1; i++) {
      r = r->next;
    }
    L = r->next;
    r->next = L->next;
    cout << L->data << " ";
    delete L;
  }
  cout << endl << "Josephus is No." << L->data;

  return 0;
}