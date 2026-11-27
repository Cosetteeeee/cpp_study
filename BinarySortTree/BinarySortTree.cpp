#include "BinarySortTree.hpp"

bool InsertBST(BSTree &T, ElemType e) {
  if (T == nullptr) {
    T = new BSTNode;
    T->data = e;
    T->lchild = nullptr;
    T->rchild = nullptr;
    return true;
  }
  if (T->data == e) {
    return false;
  }
  if (T->data > e) {
    return InsertBST(T->lchild, e);
  }
  return InsertBST(T->rchild, e);
}

void CreateBST(BSTree &T,const vector<ElemType> &keys){
  T=nullptr;
  for (ElemType e :keys) {
    InsertBST(T, e);
  }
}

void PreorderTraverse(const BSTree &T) {
  if (T == nullptr) {
    return;
  }
  cout << T->data << " ";
  PreorderTraverse(T->lchild);
  PreorderTraverse(T->rchild);
}

void InorderTraverse(const BSTree &T) {
  if (T == nullptr) {
    return;
  }
  InorderTraverse(T->lchild);
  cout << T->data << " ";
  InorderTraverse(T->rchild);
}

void PostorderTraverse(const BSTree &T) {
  if (T == nullptr) {
    return;
  }
  PostorderTraverse(T->lchild);
  PostorderTraverse(T->rchild);
  cout << T->data << " ";
}

void LevelOrderTraverse(const BSTree &T) {
  if (T == nullptr) {
    return;
  }
  queue<BSTree> Q;
  Q.push(T);
  while (!Q.empty()) {
    BSTree p = Q.front();
    Q.pop();
    cout << p->data << " ";
    if (p->lchild != nullptr) {
      Q.push(p->lchild);
    }
    if (p->rchild != nullptr) {
      Q.push(p->rchild);
    }
  }
}

int TreeHeight(const BSTree &T) {
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

int NodeCount(const BSTree &T) {
  if (T == nullptr) {
    return 0;
  }
  return 1 + NodeCount(T->lchild) + NodeCount(T->rchild);
}

int LeafCount(const BSTree &T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild == nullptr && T->rchild == nullptr) {
    return 1;
  }
  return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int NonLeafCount(const BSTree &T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild == nullptr && T->rchild == nullptr) {
    return 0;
  }
  return 1 + NonLeafCount(T->lchild) + NonLeafCount(T->rchild);
}

bool RecurSearchBST(const BSTree &T, ElemType key) {
  if (T == nullptr) {
    return false;
  }
  if (T->data == key) {
    return true;
  }
  if (key > T->data) {
    return RecurSearchBST(T->rchild, key);
  }
  return RecurSearchBST(T->lchild, key);
}

bool NonRecurSearchBST(const BSTree &T, ElemType key) {
  if (T == nullptr) {
    return false;
  }
  BSTree p = T;
  while (p) {
    if (key > p->data) {
      p = p->rchild;
    } else if (key < p->data) {
      p = p->lchild;
    } else {
      return true;
    }
  }
  return false;
}

void DestroyTree(BSTree &T) {
  if (T == nullptr) {
    return;
  }
  DestroyTree(T->lchild);
  DestroyTree(T->rchild);
  delete T;
  T = nullptr;
}