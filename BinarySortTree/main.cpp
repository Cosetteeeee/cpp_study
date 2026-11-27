#include "BinarySortTree.hpp"

int main() {
  BSTree T = nullptr;
  vector<ElemType> keys;
  ElemType x;
  cout << "请输入关键字序列（以 0 结束）：" << endl;
  while (cin >> x) {
    if (x == 0) {
      break;
    }
    keys.push_back(x);
  }
  CreateBST(T, keys);

  cout << "先序序列：";
  PreorderTraverse(T);
  cout << endl;
  cout << "中序序列：";
  InorderTraverse(T);
  cout << endl;
  cout << "后序序列：";
  PostorderTraverse(T);
  cout << endl;
  cout << "层次遍历序列：";
  LevelOrderTraverse(T);
  cout << endl;
  cout << "树的高度：" << TreeHeight(T) << endl;
  cout << "结点总数：" << NodeCount(T) << endl;
  cout << "叶子结点数：" << LeafCount(T) << endl;
  cout << "非叶子结点数：" << NonLeafCount(T) << endl;
  cout << "输入一个整数，开始查找：";
  ElemType key = 0;
  cin >> key;
  cout << "查找" << key << ":" << endl;
  if (NonRecurSearchBST(T, key)) {
    cout << "true";
  } else {
    cout << "false";
  }
  cout << "(非递归)" << endl;
  if (RecurSearchBST(T, key)) {
    cout << "true";
  } else {
    cout << "false";
  }
  cout << "(递归)" << endl;
  DestroyTree(T);
  return 0;
}