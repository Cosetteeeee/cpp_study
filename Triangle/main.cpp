#include "Triangle.hpp"

void Triangle(int n) {
  CircleQueue Q;
  InitQueue(Q);
  EnQueue(Q, 1);
  for (int i = 1; i <= n; i++) {
    int pre = 0;
    for (int k = i; k < n; k++) {
      cout << " ";
    }
    for (int j = 1; j <= i; j++) {
      ElemType cur;
      DeQueue(Q, cur);
      cout << cur << " ";
      EnQueue(Q, pre + cur);
      pre = cur;
    }
    EnQueue(Q, 1);
    cout << endl;
  }
  DestroyQueue(Q);
}

int main() {
  int n;

  cout << "请输入杨辉三角的行数：";
  cin >> n;

  if (n <= 0) {
    cout << "行数必须大于 0" << endl;
    return 0;
  }

  if (n + 2 > MAXSIZE) {
    cout << "行数过大" << endl;
    return 0;
  }

  Triangle(n);

  return 0;
}
