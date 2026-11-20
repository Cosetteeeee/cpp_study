#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef char ElemType;

typedef struct BiTNode {
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct {
  BiTree *base;
  BiTree *top;
  int stacksize;
} BiTreeStack;

typedef struct {
  BiTree *base;
  int front;
  int rear;
} BiTreeQueue;

void Create(BiTree &T);
void PreorderTraverse(const BiTree &T);
void InorderTraverse(const BiTree &T);
void PostorderTraverse(const BiTree &T);
void InitStack(BiTreeStack &S);
bool StackEmpty(const BiTreeStack &S);
bool Push(BiTreeStack &S, BiTree e);
bool Pop(BiTreeStack &S, BiTree &e);
void DestroyStack(BiTreeStack &S);
void NonRecurPre(const BiTree &T);
void NonRecurIn(const BiTree &T);
void InitQueue(BiTreeQueue &Q);
bool QueueEmpty(const BiTreeQueue &Q);
bool EnQueue(BiTreeQueue &Q, BiTree e);
bool DeQueue(BiTreeQueue &Q, BiTree &e);
void DestroyQueue(BiTreeQueue &Q);
void LevelOrderTraverse(const BiTree &T);
int TreeHeight(const BiTree &T);
int NodeCount(const BiTree &T);
int LeafCount(const BiTree &T);
int NonLeafCount(const BiTree &T);
bool FindSecondPreorder(const BiTree &T, ElemType &x);
bool DeleteSubtree(BiTree &T, ElemType x);
void DestroyTree(BiTree &T);