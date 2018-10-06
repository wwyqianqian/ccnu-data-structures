#include <iostream>
#include "../linkedListWithoutHeadNodeFunctionHub.h"
using namespace std;

int main() {
    LinkList LA;
    LinkedListCreatTailInsert(LA);
    cout <<  ListLength(LA);
    return 0;
}