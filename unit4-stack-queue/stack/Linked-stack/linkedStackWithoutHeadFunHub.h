#ifndef LINKED_STACK_WITHOUT_HEAD_FUN_HUB_H
#define LINKED_STACK_WITHOUT_HEAD_FUN_HUB_H
using namespace std;

typedef int SElemType;
typedef struct LNode {
    SElemType data; // data
    struct LNode *next; // pointer
} LNode, *LinkList;

typedef LinkList LinkStack;


// Function1: Initialize a linked stack
void InitStack(LinkStack &S) {
    S = new LNode;
    S->data = NULL; // temporary
    S->next = nullptr;
}


// Function2: Destroy the stack
void DestroyStack(LinkStack &S) {
    LNode *p;
    while (S != nullptr) {
        p = S->next;
        delete S;
        S = p;
    }
}


// Function3: Clear the existing stack
void ClearStack(LinkStack &S) {
    LNode *p;
    while (S->next != nullptr) {
        p = S->next;
        S->next = p->next;
        delete p;
    }
    S->data = NULL;
}


// Function4: Return TRUE if the Stack is empty
bool StackEmpty(LinkStack S) {
    return S->data == NULL && S->next == nullptr;
}


// Function5: Return the number of elements
int StackLength(LinkStack S) {
    if (S->data == NULL && S->next == nullptr) {
        return 0;
    }
    LNode *p;
    p = S->next;

    int cou = 0;
    while (p != nullptr) {
        cou++;
        p = p->next;
    }
    return cou;
}


// Function6: Get the top element of the stack, store it as e
bool GetTop(LinkStack S, SElemType &e) {
    if (!S) {
        return false;
    } else {
        e = S->data;
        return true;
    }
}


// Function7: Push an element 'e' to the stack
void Push(LinkStack &S, SElemType e) {
    LNode *p = new LNode;
    p->data = e;
    p->next = S;
    S = p;
}


// Function8: Pop the top element of the existing stack, store it as e
bool Pop(LinkStack &S, SElemType &e) {
    if (S) {
        LNode *p = S;
        S = S->next;
        e = p->data;
        delete p;
        return true;
    } else {
        return false;
    }
}


// Function9: Pop every element of the existing stack
bool StackTraverse(LinkStack S) {
    LNode *p = S;
    if (p->data != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    return true;
}


#endif