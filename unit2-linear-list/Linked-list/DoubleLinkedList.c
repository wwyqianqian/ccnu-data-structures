// 双向链表
typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;

// 非空双向链表
L->next->data = A1;
L->prior->data = An;
L->next->prior == L->prior->next == NULL;
