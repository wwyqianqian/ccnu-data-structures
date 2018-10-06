#include <iostream>
using namespace std;

typedef char ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->data = NULL;
    L->next = NULL;
}

LinkList LinkedListCreatTailInsert(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = NULL;
    LNode *s; LNode *p; p = L;

    char x;
    scanf("%c", &x);
    while (x != '!') { // End your string with char '!'
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        p->next = s;
        p = s;
        scanf("%c", &x);
    }
    p->next = NULL;
    return L;
}

void PriorElemNode(LinkList L, ElemType cur_e, LinkList &pre_e) {
    LNode *q;
    q = L;
    while (q->next->next->data != cur_e) {
        q = q->next;
    }
    pre_e = q;
}


void ListTraverse(LinkList L) {
    LNode *p;
    p = L->next;
    cout << p->data << " ";
    while (p->next != NULL) {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}

void InsertElem(LinkList &L, ElemType c, ElemType e) {
    LNode *p; p = L->next;
    if (p->data != c) {
        p = p->next;
    }

    LNode *pre_e;
    PriorElemNode(L, c, pre_e);
    ListTraverse(pre_e);

    LNode *pNew;
    InitList(pNew);
    pNew->data = e;
    pNew->next = p;
    pre_e->next = pNew;

}


int main() {
    LinkList LA;
    LinkedListCreatTailInsert(LA);
//    ListTraverse(LA);

    InsertElem(LA, 'a', 'h');
    ListTraverse(LA);

    return 0;


}