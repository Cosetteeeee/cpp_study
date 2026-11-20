#include "BinaryTree.hpp"

void Create(BiTree &T) {
  char ch;
  cin >> ch;
  if (ch == '#') {
    T = nullptr;
  } else {
    T = new BiTNode;
    T->data = ch;
    Create(T->lchild);
    Create(T->rchild);
  }
}

void PreorderTraverse(const BiTree &T) {
  if (T == nullptr) {
    return;
  }
  cout << T->data << " ";
  PreorderTraverse(T->lchild);
  PreorderTraverse(T->rchild);
}

void InorderTraverse(const BiTree &T) {
  if (T == nullptr) {
    return;
  }
  InorderTraverse(T->lchild);
  cout << T->data << " ";
  InorderTraverse(T->rchild);
}

void PostorderTraverse(const BiTree &T) {
  if (T == nullptr) {
    return;
  }
  PostorderTraverse(T->lchild);
  PostorderTraverse(T->rchild);
  cout << T->data << " ";
}

void InitStack(BiTreeStack &S) {
  S.base = new BiTree[MAXSIZE];
  S.top = S.base;
  S.stacksize = MAXSIZE;
}

bool StackEmpty(const BiTreeStack &S) { return S.top == S.base; }

bool Push(BiTreeStack &S, BiTree e) {
  if (S.top - S.base >= S.stacksize) {
    return false;
  }
  *S.top = e;
  S.top++;
  return true;
}

bool Pop(BiTreeStack &S, BiTree &e) {
  if (StackEmpty(S)) {
    return false;
  }
  S.top--;
  e = *S.top;
  return true;
}

void DestroyStack(BiTreeStack &S) {
  delete[] S.base;
  S.base = nullptr;
  S.top = nullptr;
  S.stacksize = 0;
}

void NonRecurPre(const BiTree &T) {
  BiTreeStack S;
  InitStack(S);
  BiTree p = T;
  while (p != nullptr || !StackEmpty(S)) {
    if (p != nullptr) {
      cout << p->data << " ";
      if (!Push(S, p)) {
        cout << "栈空间不足";
        DestroyStack(S);
        return;
      }
      p = p->lchild;
    } else {
      Pop(S, p);
      p = p->rchild;
    }
  }
  DestroyStack(S);
}

void NonRecurIn(const BiTree &T) {
  BiTreeStack S;
  InitStack(S);
  BiTree p = T;
  while (p != nullptr || !StackEmpty(S)) {
    if (p != nullptr) {
      if (!Push(S, p)) {
        cout << "栈空间不足";
        DestroyStack(S);
        return;
      }
      p = p->lchild;
    } else {
      Pop(S, p);
      cout << p->data << " ";
      p = p->rchild;
    }
  }
  DestroyStack(S);
}

void InitQueue(BiTreeQueue &Q) {
  Q.base = new BiTree[MAXSIZE];
  Q.front = 0;
  Q.rear = 0;
}

bool QueueEmpty(const BiTreeQueue &Q) { return Q.front == Q.rear; }

bool EnQueue(BiTreeQueue &Q, BiTree e) {
  if ((Q.rear + 1) % MAXSIZE == Q.front) {
    return false;
  }

  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXSIZE;
  return true;
}

bool DeQueue(BiTreeQueue &Q, BiTree &e) {
  if (QueueEmpty(Q)) {
    return false;
  }

  e = Q.base[Q.front];
  Q.front = (Q.front + 1) % MAXSIZE;
  return true;
}

void DestroyQueue(BiTreeQueue &Q) {
  delete[] Q.base;
  Q.base = nullptr;
  Q.front = 0;
  Q.rear = 0;
}

void LevelOrderTraverse(const BiTree &T) {
  if (T == nullptr) {
    return;
  }
  BiTreeQueue Q;
  InitQueue(Q);
  if (!EnQueue(Q, T)) {
    cout << "队列空间不足";
    DestroyQueue(Q);
    return;
  }
  while (!QueueEmpty(Q)) {
    BiTree p;
    DeQueue(Q, p);
    cout << p->data << " ";
    if (p->lchild != nullptr) {
      if (!EnQueue(Q, p->lchild)) {
        cout << "队列空间不足";
        DestroyQueue(Q);
        return;
      }
    }
    if (p->rchild != nullptr) {
      if (!EnQueue(Q, p->rchild)) {
        cout << "队列空间不足";
        DestroyQueue(Q);
        return;
      }
    }
  }
  DestroyQueue(Q);
}

int TreeHeight(const BiTree &T) {
  if (T == nullptr) {
    return 0;
  }
  int leftHeight = TreeHeight(T->lchild);
  int rightHeight = TreeHeight(T->rchild);
  if (leftHeight > rightHeight) {
    return leftHeight + 1;
  }
  return rightHeight + 1;
}

int NodeCount(const BiTree &T) {
  if (T == nullptr) {
    return 0;
  }
  return 1 + NodeCount(T->lchild) + NodeCount(T->rchild);
}

int LeafCount(const BiTree &T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild == nullptr && T->rchild == nullptr) {
    return 1;
  }
  return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int NonLeafCount(const BiTree &T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild == nullptr && T->rchild == nullptr) {
    return 0;
  }
  return 1 + NonLeafCount(T->lchild) + NonLeafCount(T->rchild);
}

bool FindSecondPreorder(const BiTree &T, ElemType &x) {
  if (T == nullptr) {
    return false;
  }
  if (T->lchild != nullptr) {
    x = T->lchild->data;
    return true;
  }
  if (T->rchild != nullptr) {
    x = T->rchild->data;
    return true;
  }
  return false;
}

bool DeleteSubtree(BiTree &T, ElemType x) {
  if (T == nullptr) {
    return false;
  }
  if (T->data == x) {
    DestroyTree(T);
    return true;
  }
  if (DeleteSubtree(T->lchild, x)) {
    return true;
  }
  return DeleteSubtree(T->rchild, x);
}

void DestroyTree(BiTree &T) {
  if (T == nullptr) {
    return;
  }
  DestroyTree(T->lchild);
  DestroyTree(T->rchild);
  delete T;
  T = nullptr;
}