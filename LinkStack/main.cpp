#include "LinkStack.h"

int main() {
    LinkStack S;
    char e;

    InitStack(S);
    cout << "初始空栈:" << StackEmpty(S) << endl;

    Push(S,'a'); Push(S,'b'); Push(S,'c'); Push(S,'d');
    cout << "遍历栈:";
    Traverse(S);

    GetTop(S, e);
    cout << "栈顶元素:" << e << endl;

    Pop(S, e);
    cout << "弹出元素:" << e << endl;
    cout << "遍历栈:";
    Traverse(S);

    cout << "栈是否空:" << StackEmpty(S) << endl;

    while (Pop(S, e) == OK);
    cout << "弹空后:" << StackEmpty(S) << endl;
    cout << "空栈再弹:" << Pop(S, e) << endl;
    cout << "空栈取顶:" << GetTop(S, e) << endl;

    Push(S,'x'); Push(S,'y');
    ClearStack(S);
    cout << "清空后空栈:" << StackEmpty(S) << endl;
    cout << "清空后遍历:";
    Traverse(S);

    Push(S,'m');
    cout << "清空后复用:";
    Traverse(S);

    DestroyStack(S);
    return 0;
}
