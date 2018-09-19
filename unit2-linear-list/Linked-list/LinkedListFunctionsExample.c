// 单链表的节点类型描述
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 1. 采用头插法建立单链表
LinkList CreatList1(LinkList &L) {
    LNode *s; int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
};