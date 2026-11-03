#include "DancePartner.hpp"

void DancePartner(LinkQueue &men, LinkQueue &women) {
  Dancer man;
  Dancer woman;
  int pair = 0;
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
}

int main() {
  LinkQueue men;
  LinkQueue women;
  DancePartner(men, women);
  return 0;
}