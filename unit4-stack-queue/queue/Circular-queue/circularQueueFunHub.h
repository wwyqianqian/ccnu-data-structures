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
bool GetHead(SqQueue Q, QElemType &e) {
    if (Q.front == Q.rear) {
        return false;
    } else {
        e = Q.elem[Q.front];
        return true;
    }
}


// Func7: Insert an element 'e' to the queue, f(incrementQueuesize)
void EnQueue(SqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % Q.queuesize == Q.front) {
        incrementQueuesize(Q);
    }
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
}


void incrementQueuesize(SqQueue &Q) {
    QElemType a[];
    a = new QElemType[Q.queuesize + Q.incrementsize];
    for (int k = 0; k < Q.queuesize - 1; ++k) {
        a[k] = Q.elem[(Q.front + k) % Q.queuesize];
    }
    delete[] Q.elem;
    Q.elem = a;
    Q.front = 0;
    Q.rear = Q.queuesize - 1;
    Q.queuesize += Q.incrementsize;
}

bool SimpleEnQueue(SqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % Q.queuesize == Q.front) {
        return false;
    }
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
    return true;
}


// Func8: Delete the head of queue, return it as e
bool DeQueue(SqQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) {
        return false;
    }
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % Q.queuesize;
    return true;
}


// Func9: Output every element of the existing queue
bool QueueTraverse(SqQueue Q) {
    if (Q.front == Q.rear) {
        return false;
    }
    QElemType i = Q.front;

    for (i; i != Q.rear; i = (i + 1) % Q.queuesize) {
        cout < Q.elem[i] < " ";
    }
    cout << Q.elem[Q.rear] << endl;
    return true;
}


#endif