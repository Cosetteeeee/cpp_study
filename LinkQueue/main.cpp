#include "LinkQueue.hpp"

// 带头结点版本的链队列
int main() {
    LinkQueue Q;
    ElemType e;

    if (InitQueue(Q) != OK) {
        cout << "队列初始化失败" << endl;
        return 0;
    }

    cout << "入队：1 2 3 4 5" << endl;
    for (int i = 1; i <= 5; i++) {
        EnQueue(Q, i);
    }

    cout << "遍历队列：";
    QueueTraverse(Q);

    if (DeQueue(Q, e) == OK) {
        cout << "出队元素：" << e << endl;
    } else {
        cout << "出队失败，队列为空" << endl;
    }
    cout << "当前队列：";
    QueueTraverse(Q);

    if (DeQueue(Q, e) == OK) {
        cout << "出队元素：" << e << endl;
    } else {
        cout << "出队失败，队列为空" << endl;
    }
    cout << "当前队列：";
    QueueTraverse(Q);

    EnQueue(Q, 6);
    EnQueue(Q, 7);
    cout << "入队 6、7 后：";
    QueueTraverse(Q);

    if (GetHead(Q, e) == OK) {
        cout << "队头元素：" << e << endl;
    } else {
        cout << "队列为空，没有队头元素" << endl;
    }

    cout << "队中元素个数：" << QueueLength(Q) << endl;

    ClearQueue(Q);
    cout << "清空后遍历：";
    QueueTraverse(Q);

    DestroyQueue(Q);

    return 0;
}
