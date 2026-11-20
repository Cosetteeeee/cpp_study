#include "BinaryTree.hpp"
#include <iostream>

int main() {
  BiTree T = nullptr;
  ElemType x;
  cout << "输入样例：ABC##DE#G##F###" << endl;
  cout << "输入序列：";
  Create(T);
  cout << "先序序列：";
  PreorderTraverse(T);
  cout << endl;
  cout << "中序序列：";
  InorderTraverse(T);
  cout << endl;
  cout << "后序序列：";
  cout << endl;
  cout << "非递归先序：";
  NonRecurPre(T);
  cout << endl;
  cout << "非递归中序：";
  NonRecurIn(T);
  cout << endl;
  cout << "层次遍历：";
  LevelOrderTraverse(T);
  cout << endl;
  cout << "树的高度：" << TreeHeight(T) << endl;
  cout << "结点总数：" << NodeCount(T) << endl;
  cout << "叶子结点数：" << LeafCount(T) << endl;
  cout << "非叶子结点数：" << NonLeafCount(T) << endl;
  if (FindSecondPreorder(T, x)) {
    cout << "先序序列中第2个结点的值：" << x << endl;
    if (DeleteSubtree(T, x)) {
      cout << "已删除以" << x << "为根的子树。" << endl;
    } else {
      cout << "没有找到值为" << x << "的结点。" << endl;
    }
  } else {
    cout << "二叉树不足2个结点，无法取得x。" << endl;
  }
  DestroyTree(T);
  cout << "二叉树已全部销毁。" << endl;
  return 0;
}