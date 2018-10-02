#include <stdio.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data; // data
    struct LNode *next; // pointer
} LNode, *LinkList;

void InitList(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    (*L)->data = NULL;
    (*L)->next = NULL;
}


int main() {
    LinkList LA;
    printf("%p \n", LA);
    InitList(LA);
    printf("%p", LA);
    return 0;
}