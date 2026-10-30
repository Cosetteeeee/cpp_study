#include"SqStack.h"

int main() {
	SqStack S;
	SElemType e;

	InitStack(S);
	cout << "初始空栈:" << StackEmpty(S) << endl;

	for (int i = 1; i <= 5; i++) Push(S, i);
	cout << "遍历栈:";
	Traverse(S);

	GetTop(S, e);
	cout << "栈顶元素:" << e << endl;

	Pop(S, e);
	cout << "弹出元素:" << e << endl;
	cout << "遍历栈:";
	Traverse(S);

	cout << "栈是否满:" << StackFull(S) << endl;
	while (Push(S, 0) == OK);
	cout << "压满后:" << StackFull(S) << endl;
	cout << "满栈再压:" << Push(S, 1) << endl;

	ClearStack(S);
	cout << "清空后空栈:" << StackEmpty(S) << endl;
	cout << "清空后遍历:";
	Traverse(S);

	DestroyStack(S);
	return 0;
}
