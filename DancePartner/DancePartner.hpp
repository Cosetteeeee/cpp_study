#include <iostream>
#include <string>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
  string name;
  char sex;
} Dancer;
typedef Dancer ElemType;

typedef struct QNode {
  ElemType data;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
  QueuePtr front;
  QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q, ElemType e);
Status DeQueue(LinkQueue &Q, ElemType &e);
Status GetHead(const LinkQueue &Q, ElemType &e);
Status QueueEmpty(const LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
int QueueLength(const LinkQueue &Q);
void QueueTraverse(const LinkQueue &Q);