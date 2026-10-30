#include"SqStack.h"

Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base) {
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize) {
		return ERROR;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base) {
		return ERROR;
	}
	e = *--S.top;
	return OK;
}

Status GetTop(SqStack& S, SElemType& e) {
	if (S.top == S.base) {
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

Status Traverse(SqStack& S) {
	SElemType* p = S.base;
	while (p<S.top) {
		cout << *p << " ";
		p++;
	}
	cout << endl;
	return OK;
}

Status ClearStack(SqStack& S) {
	S.top = S.base;
	return OK;
}

Status DestroyStack(SqStack& S) {
	delete[] S.base;
	S.base = S.top = nullptr;
	S.stacksize = 0;
	return OK;
}

Status StackEmpty(SqStack& S) {
	if (S.base == S.top) {
		return OK;
	}
	return ERROR;
}

Status StackFull(SqStack& S) {
	if (S.top - S.base == S.stacksize) {
		return OK;
	}
	return ERROR;
}