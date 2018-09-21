typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode, *DuLinkList;


// 空的双向循环链表
L->next == L->prior == L;

// 在带表头结点的双向循环链表 L 中 P 结点之前插入结点 S
void ListInsert_DuL(DuLinkList &L, DuLNode *p, DuLNode *s) {
    s->prior = p->prior;
    s->next = p;
    p->prior->next = s;
    p->prior = s;
}

// 删除带头结点的双向循环链表 L 中的 P 结点，以 e 返回他的数据元素
void ListDel_DuL(DuLinkList &L, DuLNode *p, ElemType &e) {
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
}