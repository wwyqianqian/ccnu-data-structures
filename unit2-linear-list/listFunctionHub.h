#ifndef LIST_FUNCTION_HUB_H
#define LIST_FUNCTION_HUB_H

const LIST_INIT_SIZE = 100;
const LIST_INCREMENT_SIZE = 10;

typedef int ElemType;
typedef struct {
    ElemType *elem; // elements
    int length; // how many elements
    int listSize; // how large is the list
    int incrementSize; // increase how many ElemType
} List;


// Function1: Initialize a List
void InitList(List &L) {
    L.elem = new ElemType[LIST_INIT_SIZE];

    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    L.incrementSize = LIST_INCREMENT_SIZE;
}






#endif