#include "DancePartner.hpp"

void DancePartner(LinkQueue &men, LinkQueue &women) {
  Dancer man;
  Dancer woman;
  int pair = 0;
  if (InitQueue(men) != OK) {
    cout << "男队初始化失败。" << endl;
    return;
  }
  if (InitQueue(women) != OK) {
    cout << "女队初始化失败。" << endl;
    DestroyQueue(men);
    return;
  }
  int n;
  cout << "请输入舞者总人数：";
  cin >> n;

  if (n < 0) {
    cout << "舞者人数不能为负数。" << endl;
    DestroyQueue(men);
    DestroyQueue(women);
    return;
  }

  cout << "请一次性输入所有舞者的姓名和性别（M 表示男，F 表示女）：" << endl;

  for (int i = 0; i < n; i++) {
    Dancer dancer;

    cin >> dancer.name >> dancer.sex;

    if (dancer.sex == 'M') {
      EnQueue(men, dancer);
    } else if (dancer.sex == 'F') {
      EnQueue(women, dancer);
    } else {
      cout << "性别输入错误，请输入 M 或 F。" << endl;
      i--;
    }
  }
  while (!QueueEmpty(men) && !QueueEmpty(women)) {
    DeQueue(men, man);
    DeQueue(women, woman);
    pair++;
    cout << "第 " << pair << " 对：" << man.name << "(" << man.sex << ")"
         << " 与 " << woman.name << "(" << woman.sex << ")" << endl;
  }
  cout << endl;
  cout << "本轮共配对 " << pair << " 对。" << endl;
  if (QueueEmpty(men) == ERROR) {
    GetHead(men, man);
    cout << "还有 " << QueueLength(men) << " 位男士等待配对。" << endl;
    cout << "下一位等待的男士是：" << man.name << "(" << man.sex << ")" << endl;
    cout << "仍未配对的男队：";
    QueueTraverse(men);
  } else if (QueueEmpty(women) == ERROR) {
    GetHead(women, woman);
    cout << "还有 " << QueueLength(women) << " 位女士等待配对。" << endl;
    cout << "下一位等待的女士是：" << woman.name << "(" << woman.sex << ")"
         << endl;
    cout << "仍未配对的女队：";
    QueueTraverse(women);
  } else {
    cout << "所有舞者均已完成配对，无人等待。" << endl;
  }

  // 释放队列
  DestroyQueue(men);
  DestroyQueue(women);
}

int main() {
  LinkQueue men;
  LinkQueue women;
  DancePartner(men, women);
  return 0;
}
