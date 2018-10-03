#include <iostream>
#include "linkedListWithoutHeadNodeFunctionHub.h"




int main() {
    LinkList LA;
    printf("%p \n", LA);
    InitList(LA);
    printf("%p \n", LA);

    DestroyList(LA);
    printf("%p \n", LA);
    return 0;
}