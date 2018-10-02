#ifndef Linked_LIST_WITH_HEAD_NODE_FUNCTION_HUB_H
#define Linked_LIST_WITH_HEAD_NODE_FUNCTION_HUB_H
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data; // data
    struct LNode *next; // pointer
} LNode, *LinkList;


// Function1: Initialize a List
//void InitList(LinkList &L) {
//    L = (LinkList)malloc(sizeof(LNode));
//    L->data = NULL;
//    L->next = NULL;
//}

void InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    (*L)->data = NULL;
    (*L)->next = NULL;
}






























#endif