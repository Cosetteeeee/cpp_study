#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef int ElemType;

typedef struct BSTNode {
  ElemType data;
  struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

bool InsertBST(BSTree &T, ElemType e);
void CreateBST(BSTree &T, const vector<ElemType> &keys);
void PreorderTraverse(const BSTree &T);
void InorderTraverse(const BSTree &T);
void PostorderTraverse(const BSTree &T);
void LevelOrderTraverse(const BSTree &T);
int TreeHeight(const BSTree &T);
int NodeCount(const BSTree &T);
int LeafCount(const BSTree &T);
int NonLeafCount(const BSTree &T);
bool RecurSearchBST(const BSTree &T, ElemType key);
bool NonRecurSearchBST(const BSTree &T, ElemType key);
void DestroyTree(BSTree &T);