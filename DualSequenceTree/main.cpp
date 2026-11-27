#include "DualSequenceTree.hpp"

int main() {
  string pre, in1, in2, post;
  cout << "请依次输入：第一条先序 第一条中序 第二条中序 第二条后序" << endl;
  cin >> pre >> in1 >> in2 >> post;

  BiTree T1 = nullptr;
  CreateByPreIn(T1, pre, in1);
  cout << "先序+中序构造" << endl;
  cout << "先序：";
  PreorderTraverse(T1);
  cout << endl;
  cout << "中序：";
  InorderTraverse(T1);
  cout << endl;
  cout << "后序：";
  PostorderTraverse(T1);
  cout << endl;
  cout << "层次：";
  LevelOrderTraverse(T1);
  cout << endl;
  cout << "树的高度：" << TreeHeight(T1) << endl;
  cout << "结点总数：" << NodeCount(T1) << endl;
  cout << "叶子结点数：" << LeafCount(T1) << endl;
  cout << "非叶子结点数：" << NonLeafCount(T1) << endl;
  DestroyTree(T1);

  BiTree T2 = nullptr;
  CreateByInPost(T2, in2, post);
  cout << "中序+后序构造" << endl;
  cout << "先序：";
  PreorderTraverse(T2);
  cout << endl;
  cout << "中序：";
  InorderTraverse(T2);
  cout << endl;
  cout << "后序：";
  PostorderTraverse(T2);
  cout << endl;
  cout << "层次：";
  LevelOrderTraverse(T2);
  cout << endl;
  cout << "树的高度：" << TreeHeight(T2) << endl;
  cout << "结点总数：" << NodeCount(T2) << endl;
  cout << "叶子结点数：" << LeafCount(T2) << endl;
  cout << "非叶子结点数：" << NonLeafCount(T2) << endl;
  DestroyTree(T2);

  return 0;
}
