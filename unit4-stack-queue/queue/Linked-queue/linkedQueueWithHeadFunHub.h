#ifndef LINKED_QUEUE_WITH_HEAD_FUN_HUB_H
#define LINKED_QUEUE_WITH_HEAD_FUN_HUB_H
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data; // data
    struct LNode *next; // pointer
} LNode, *LinkList;

typedef LinkList QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;


// Func1: Initialize a linked queue
void InitQueue(LinkQueue &Q) {
     Q.front = Q.rear = new LNode; //???
     Q.front->data = NULL;
     Q.front->next = nullptr;
}


// Func2: Destroy the queue
void DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
}


// Func3: Clear the existing queue
void ClearQueue(LinkQueue &Q) {
    LNode *p;
    while (Q.front->next != nullptr) {
        p = Q.front->next;
        Q.front->next = p->next;
        delete p;
    }
}


// Func4: Return TRUE if the queue is empty
bool QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}


// Func5: Return the number of elements
int QueueLength(LinkQueue Q) {
    LNode *p;
    p = Q.front->next;

    int cou = 0;
    while (p != nullptr) {
        cou++;
        p = p->next;
    }
    return cou;
}


// Func6: Get the head data of the queue, store it as e
bool GetHead(LinkQueue Q, ElemType &e) {
    if (Q.front == Q.rear) {
        return false;
    }
    e = Q.front->next->data;
    return true;
}


// Func7: Insert an element 'e' to the queue
void EnQueue(LinkQueue &Q, ElemType e) {
    LNode *p;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p; // tail
    Q.rear = p; // update the rear
}


// Func8: Delete the head of queue, return it as e
bool DeQueue(LinkQueue &Q, ElemType &e) {
    if (Q.front == Q.rear) {
        return false;
    }
    LNode *p;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    delete p;
    return true;
}


// Func9: Output every element of the existing queue
bool QueueTraverse(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return false;
    }
    LNode *p;
    p = Q.front->next;
    cout << p->data << " ";
    while (p->next != nullptr) {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
    return true;
}


#endif