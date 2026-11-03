#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType *base;
    int front;
    int rear;
} CircleQueue;

Status InitQueue(CircleQueue &Q);
Status EnQueue(CircleQueue &Q, ElemType e);
Status DeQueue(CircleQueue &Q, ElemType &e);
Status GetHead(const CircleQueue &Q, ElemType &e);
Status QueueEmpty(const CircleQueue &Q);
Status QueueFull(const CircleQueue &Q);
Status DestroyQueue(CircleQueue &Q);
Status ClearQueue(CircleQueue &Q);
int QueueLength(const CircleQueue &Q);
void QueueTraverse(const CircleQueue &Q);