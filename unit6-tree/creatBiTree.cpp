#include <iostream>
// #include "../unit4-stack-queue/queue/Linked-queue/linkedQueueWithHeadFunHub.h"
using namespace std;


typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef BiTree QElemType;
typedef struct LNode {
    QElemType data; 
    struct LNode *next;
} LNode, *LinkList;

typedef LinkList QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;


void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new LNode; 
    Q.front->data = NULL;
    Q.front->next = nullptr;
}
bool QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}
void EnQueue(LinkQueue &Q, QElemType e) {
    QueuePtr p = new LNode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p; // tail
    Q.rear = p; // update the rear
}
bool DeQueue(LinkQueue &Q, QElemType &e) {
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


void createBiTree(BiTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = nullptr;
    } else {
        T = new BiTNode;
        T->data = ch;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
} 

void preOrder(BiTree T, void(*visit)(BiTree)) {
    if (T) {
        visit(T);
        preOrder(T->lchild, visit);
        preOrder(T->rchild, visit);
    }
}

void inOrder(BiTree T, void(*visit)(BiTree)) {
    if (T) {
        inOrder(T->lchild, visit);
        visit(T);
        inOrder(T->rchild, visit);
    }
}

void postOrder(BiTree T, void(*visit)(BiTree)) {
    if (T) {
        postOrder(T->lchild, visit);
        postOrder(T->rchild, visit);
        visit(T);
    }
}


void visit(BiTree T) {
    cout << T->data << " ";
}


void LevelOrder(BiTree T, LinkQueue Q, void(*visit)(BiTree)) {
    if(!T) return;
    EnQueue(Q, T);
    while (!QueueEmpty(Q)) {
        BiTree e;
        DeQueue(Q, e);
        visit(e);
        if(e->lchild) {
            EnQueue(Q, e->lchild);
        }	
        if(e->rchild) {
            EnQueue(Q, e->rchild);
        }
    }
}


int main() {
    BiTree T; 
    LinkQueue Q;
    InitQueue(Q);

    createBiTree(T);
    cout << "先序：";
    preOrder(T, visit);
    cout << endl;

    cout << "中序：";
    inOrder(T, visit);
    cout << endl;

    cout << "后序：";
    postOrder(T, visit);
    cout << endl;

    cout << "广度遍历：";
    LevelOrder(T, Q, visit);

	return 0;
}


//  ~/w/ccnu-data-structures/unit6-tree  ./a.out                      332ms  Thu Nov 29 23:32:28 2018
// AB#DE###C##
// 先序：A B D E C
// 中序：B E D A C
// 后序：E D B C A
// 广度遍历：A B C D E