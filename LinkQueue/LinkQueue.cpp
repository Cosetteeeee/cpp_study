#include "LinkQueue.hpp"

Status InitQueue(LinkQueue &Q) {
  Q.front = new QNode;
  if (Q.front == nullptr) {
    Q.rear = nullptr;
    return ERROR;
  }
  Q.front->next = nullptr;
  Q.rear = Q.front;
  return OK;
}

Status EnQueue(LinkQueue &Q, ElemType e) {
  QueuePtr p = new QNode;
  if (p == nullptr) {
    return ERROR;
  }
  p->data = e;
  p->next = nullptr;
  Q.rear->next = p;
  Q.rear = p;
  return OK;
}

Status DeQueue(LinkQueue &Q, ElemType &e) {
  if (QueueEmpty(Q)) {
    return ERROR;
  }
  QueuePtr p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  if (Q.rear == p) {
    Q.rear = Q.front;
  }
  delete p;
  return OK;
}

Status GetHead(const LinkQueue &Q, ElemType &e) {
  if (QueueEmpty(Q)) {
    return ERROR;
  }
  e = Q.front->next->data;
  return OK;
}

Status QueueEmpty(const LinkQueue &Q) {
  return Q.front == Q.rear ? OK : ERROR;
}

Status DestroyQueue(LinkQueue &Q) {
  while (Q.front != nullptr) {
    QueuePtr p = Q.front;
    Q.front = Q.front->next;
    delete p;
  }
  Q.rear = nullptr;
  return OK;
}

Status ClearQueue(LinkQueue &Q) {
  QueuePtr p = Q.front->next;
  while (p) {
    QueuePtr q = p->next;
    delete p;
    p = q;
  }
  Q.front->next = nullptr;
  Q.rear = Q.front;
  return OK;
}

int QueueLength(const LinkQueue &Q) {
  QueuePtr p = Q.front->next;
  int len = 0;
  while (p) {
    len++;
    p = p->next;
  }
  return len;
}

void QueueTraverse(const LinkQueue &Q) {
  QueuePtr p = Q.front->next;
  while (p) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}