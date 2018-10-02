#include <stdio.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data; // data
    struct LNode *next; // pointer
} LNode, *LinkList;


int main() {
    LinkList LA;
    printf("%p \n", LA);
    InitList(LA);
    printf("%p", LA);
    return 0;
}