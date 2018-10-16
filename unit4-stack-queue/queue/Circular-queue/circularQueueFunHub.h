#ifndef CIRCULAR_QUEUE_FUN_HUB_H
#define CIRCULAR_QUEUE_FUN_HUB_H
using namespace std;

const QUEUE_INIT_SIZE = 100;
const QUEUEINCREMENT = 10;

typedef int QElemType;
typedef struct {
    QElemType *elem;
    int front;
    int rear;
    int queuesize; // mod
    int incrementsize;
}SqQueue;


// Func1: Initialize a circular queue
void InitQueue(SqQueue &Q) {
    Q.elem = new QElemType[QUEUE_INIT_SIZE + 1];
    Q.queuesize = QUEUE_INIT_SIZE + 1; // mod = maxStore + 1
    Q.incrementsize = QUEUEINCREMENT;
    Q.front = Q.rear = 0;
}


// Func2: Destroy the queue
void DestroyQueue(SqQueue &Q) {
    delete[] Q.elem;
    Q.queuesize = 0
}


// Func3: Clear the existing queue
void ClearQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}


// Func4: Return TRUE if the queue is empty
bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}


// Func5: Return the number of elements
int QueueLength(SqQueue Q) {
    return (Q.rear + Q.queuesize - Q.front) % Q.queuesize;
}


// Func6: Get the head data of the queue, store it as e
bool GetHead(SqQueue Q, ElemType &e) {
    if (Q.front == Q.rear) {
        return false;
    } else {
        e = Q.elem[Q.front];
        return true;
    }
}


// 













































#endif