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

int LocateElem(LinkList L, ElemType e) {
    LNode *p;
    p = L->next;
    int cou = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        cou++;
    }
    if (p == NULL) {
        return 0;
    }
    if (p->data == e) {
        return cou;
    }
}

bool ListInsert(LinkList &L, ElemType i, ElemType e) {
    LNode *p;
    p = L->next;
    int cou = 1;
    while (cou < i && p != NULL) {
        cou++;
        p = p->next;
    }
    if (cou != i || p == NULL) {
        return false;
    }
    LNode *pNew;
    InitList(pNew);
    if (NULL == pNew) {
        printf("Error in dynamic memory allocating");
    }
    pNew->data = e;

    LNode *q;
    q = L;
    while (q->next != p) {
        q = q->next;
    }
    q->next = pNew;
    pNew->next = p;
    return true;
}

int ListDelete(LinkList &L, ElemType i, ElemType &e) {
    LNode *p;
    p = L->next;
    int cou = 1;
    while (cou < i && p != NULL) {
        cou++;
        p = p->next;
    }
    if (cou != i || p == NULL) {
        return false;
    }

    LNode *q;
    q = L;
    while (q->next != p) {
        q = q->next;
    }

    q->next = p->next;
    e = p->data;
    delete p;
    return e;
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


int main() {
    LinkList LA;
    LinkedListCreatTailInsert(LA);


    ListInsert(LA, LocateElem(LA, 'a'), 'a');
    ListTraverse(LA);

    ElemType e;
    ListDelete(LA, LocateElem(LA, 'z'), e);
    ListTraverse(LA);
    return 0;
}