#include "Triangle.hpp"
#include <iostream>

Status InitQueue(CircleQueue &Q) {
  Q.base = new ElemType[MAXSIZE];
  if (Q.base == nullptr) {
    Q.front = Q.rear = 0;
    return ERROR;
  }
  Q.front = Q.rear = 0;
  return OK;
}

Status EnQueue(CircleQueue &Q, ElemType e) {
  if (QueueFull(Q)) {
    return ERROR;
  }
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXSIZE;
  return OK;
}

Status DeQueue(CircleQueue &Q, ElemType &e) {
  if (QueueEmpty(Q)) {
    return ERROR;
  }
  e = Q.base[Q.front];
  Q.front = (Q.front + 1) % MAXSIZE;
  return OK;
}

Status GetHead(const CircleQueue &Q, ElemType &e) {
  if (QueueEmpty(Q)) {
    return ERROR;
  }
  e = Q.base[Q.front];
  return OK;
}

Status QueueEmpty(const CircleQueue &Q) {
  return Q.front == Q.rear ? OK : ERROR;
}

Status QueueFull(const CircleQueue &Q) {
  return Q.front == (Q.rear + 1) % MAXSIZE ? OK : ERROR;
}

Status DestroyQueue(CircleQueue &Q) {
  delete[] Q.base;
  Q.base = nullptr;
  Q.front = Q.rear = 0;
  return OK;
}

Status ClearQueue(CircleQueue &Q) {
  Q.front = Q.rear = 0;
  return OK;
}

int QueueLength(const CircleQueue &Q) {
  return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
void QueueTraverse(const CircleQueue &Q) {
  int i = Q.front;
  while (i != Q.rear) {
    cout << Q.base[i] << " ";
    i = (i + 1) % MAXSIZE;
  }
  cout << endl;
}