#ifndef Linked_LIST_WITH_HEAD_NODE_FUNCTION_HUB_H
#define Linked_LIST_WITH_HEAD_NODE_FUNCTION_HUB_H
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data; // data
    struct LNode *next; // pointer
} LNode, *LinkList;


// Function1: Initialize a List
void InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->data = NULL;
    L->next = NULL;
}

//void InitList(LinkList *L) { // in pointer
//    (*L) = (LNode *)malloc(sizeof(LNode));
//    (*L)->data = NULL;
//    (*L)->next = NULL;
//}

// Function2: Destroy the List
void DestroyList(LinkList &L) {
    LNode *p;
    while (L != NULL) {
        p = L->next;
        delete L;
        L = p;
    }
}

// Function3: Clear the existing List
void ClearList(LinkList &L) {
    LNode *p;
    while (L->next != NULL) {
        p = L->next;
        L->next = p->next;
        delete p;
    }
}

// Function4: Return TRUE if the List is empty
bool ListEmpty(LinkList L) {
    if (L->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function5: Return the number of elements
int ListLength(LinkList L) {
    LNode *p;
    p = L->next;

    int cou = 0;
    while (p != NULL) {
        cou++;
        p = p->next;
    }
    return cou;
}

// Function6: Return the i'th value as e
void GetElem(LinkList L, int i, ElemType &e) {
    LNode *p;
    p = L->next;
    int cou = 1;
    while (p != NULL && cou < i) {
        p = p->next;
        cou++;
    }
    if (cou == i) {
        e = p->data;
        return e;
    } else {
        return NULL;
    }
}
void GetElemNode(LinkList L, int i, LinkList &e) {
    LNode *e;
    e = L->next;
    int cou = 1;
    while (e != NULL && cou < i) {
        e = e->next;
        cou++;
    }
    if (cou == i) {
        return e;
    } else {
        return NULL;
    }
}

// Function7: Return the serial number in the list L of the first item whose value is equal to e. Else return 0.
int LocateElem(LinkList L, ElemType e) {
    LNode *p;
    p = L->next;
    int cou = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        cou++;
    }
    if (p->data == e) {
        return cou;
    } else {
        return 0;
    }
}

// Function8: Return the prior element of cur_e in the list
int PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    int cur_e_serial = LocateElem(L, cur_e);
    if (cur_e_serial == 1) {
        return NULL;
    }
    pre_e = GetElem(L, cur_e_serial - 1, e);
    return pre_e;
}
void PriorElemNode(LinkList L, ElemType cur_e, LinkList &pre_e) {
    int cur_e_serial = LocateElem(L, cur_e);
    if (cur_e_serial == 1) {
        return NULL;
    }
    pre_e = GetElemNode(L, cur_e_serial - 1, e);
    return pre_e;
}

// Function9: Return the next element of cur_e in the list
int NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    int cur_e_serial = LocateElem(L, cur_e);
    if (cur_e_serial == ListLength(L)) {
        return NULL;
    }
    next_e = GetElem(L, cur_e_serial + 1, e);
    return next_e;
}

// Function10: Insert element e at position i
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
    q = L->next;
    int count = 1;
    while (count < (i - 1) && q != NULL) {
        count++;
        q = q->next;
    }

    q->next = pNew;
    pNew->next = p;
    return true;
}


























#endif