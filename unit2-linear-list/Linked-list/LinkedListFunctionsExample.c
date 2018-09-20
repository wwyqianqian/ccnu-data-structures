// 单链表的节点类型描述
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 1. 采用头插法建立单链表 O(n)
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


// 2. 采用尾插法建立单链表 O(n)
LinkList CreatList2(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L; // 尾指针 r
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL; // 尾指针置空
    return L;
}


// 3. 按照序号查找结点值 O(n)
LNode *GetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0) {
        return L;
    }
    if (i < 1) {
        return NULL;
    }
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    return p;
}


// 4. 按照值查找链表结点 O(n)
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}


// 5. 插入结点操作
// 前插伪代码
p = GetElem(L, i - 1); // 插入位置的前驱结点。时间开销在查找的上面 O(n)。假如给定了前驱插入就为 O(1)。
s->next = p->next;
p->next = s;

// 如果 p 所指结点为链表的第一个结点，前插需要修改链表的头指针
void ListInsert_L(LinkList &L, LNode *p, LNode *s) {
    if (p == L) {
        s->next = L;
        L = s;
    } else {
        q = L;
        while (q->next != p) {
            q = q->next;
            q->next = s;
            s->next = p;
        }
    }
}

// 转化为后插的伪代码 *s 插入到 *p 之前
s->next = p->next;
p->next = s;

temp = p->data;
p->data = s->data;
s->data = temp;


// 6. 删除结点操作伪代码，将第 i 个结点删除
// 正常操作：O(n)
p = GetElem(L, i - 1);
q = p->next;
p->next = q->next;
free(q);

// 骚操作：把后继结点赋予自身，然后删除后继结点，比如删除 *p，这样时间复杂度为 O(1)
q = p->next;
p->data = p->next->data;
p->next = q->next;
free(q);


// 7. 求表长操作 O(n)
int ListLength_L(LinkList L) {
    p = L;
    k = 0;
    while (p) {
        k++;
        p = p->next;
    }
    return k;
}