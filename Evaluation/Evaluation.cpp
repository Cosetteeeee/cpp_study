#include"Evaluation.hpp"

Status InitStack(OPND& S) {
	S.base = new OPNDType[MAXSIZE];
	if (!S.base) {
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

Status Push(OPND& S, OPNDType e) {
	if (S.top - S.base == S.stacksize) {
		return ERROR;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(OPND& S, OPNDType& e) {
	if (S.top == S.base) {
		return ERROR;
	}
	e = *--S.top;
	return OK;
}

Status GetTop(OPND& S, OPNDType& e) {
	if (S.top == S.base) {
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

Status Traverse(OPND& S) {
	OPNDType* p = S.base;
	while (p<S.top) {
		cout << *p << " ";
		p++;
	}
	cout << endl;
	return OK;
}

Status ClearStack(OPND& S) {
	S.top = S.base;
	return OK;
}

Status DestroyStack(OPND& S) {
	delete[] S.base;
	S.base = S.top = nullptr;
	S.stacksize = 0;
	return OK;
}

Status StackEmpty(OPND& S) {
	if (S.base == S.top) {
		return OK;
	}
	return ERROR;
}

Status StackFull(OPND& S) {
	if (S.top - S.base == S.stacksize) {
		return OK;
	}
	return ERROR;
}
