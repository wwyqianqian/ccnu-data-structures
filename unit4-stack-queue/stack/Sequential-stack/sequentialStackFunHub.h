#ifndef SEQUENTIAL_STACK_FUNCTION_HUB_H
#define SEQUENTIAL_STACK_FUNCTION_HUB_H
using namespace std;

const int STACK_INIT_SIZE = 100;
const int STACKINCREMENT = 10;

typedef int SElemType;
typedef struct {
    SElemType *elem;
    int top; // the top element's subscript
    int stacksize; // max size
    int incrementsize; // increase capacity
} SqStack;

// Function1: Initialize a sequential stack
void InitStack(SqStack &S) {
    S.elem = new SElemType[STACK_INIT_SIZE];
    S.top = -1;
    S.stacksize = STACK_INIT_SIZE;
    S.incrementsize = STACKINCREMENT;
}

// Function2: Destroy the stack
void DestroyStack(SqStack &S) {
    if (!S.elem) {
        cout << "error";
       
    }
    delete S.elem;
    S.top = -1;
    S.stacksize = 0;
    S.incrementsize = 0;
}

// Function3: Clear the existing stack
void ClearStack(SqStack &S) {
    if (!S.elem) {
        cout << "error";
       
    }
    S.top = -1;
}

// Function4: Return TRUE if the Stack is empty
bool StackEmpty(SqStack S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

// Function5: Return the number of elements
int StackLength(SqStack S) {
    return S.top + 1;
}

// Function6: Get the top element of the stack, store it as e
bool GetTop(SqStack S, SElemType &e) {
    if (S.top == -1) {
        return false;
    }
    e = S.elem[S.top];
    return true;
}

// Function7: Push an element 'e' to the stack // 待完善（拓容）
bool Push(SqStack &S, SElemType e) {
    if (S.top == STACK_INIT_SIZE - 1) {
        return false;
    }
    S.elem[++S.top] = e;
    return true;
}

// Function8: Pop the top element of the existing stack, store it as e
bool Pop(SqStack &S, SElemType &e) {
    if (S.top == -1) {
        return false;
    }
    e = S.elem[S.top--];
    return true;
}

// Function9: Pop every element of the existing stack
bool StackTraverse(SqStack S) {
    if (S.top == -1) {
        return false;
    }
    while (S.top != -1) {
        int e = 0;
        Pop(S, e);
        cout << e << " ";
    }
    return true;
}


#endif