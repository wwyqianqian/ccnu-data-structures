#ifndef LINKED_LIST_WITH_HEAD_NODE_FUNCTION_HUB_H
#define LINKED_LIST_WITH_HEAD_NODE_FUNCTION_HUB_H
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

LinkList LinkedListCreatHeadInsert(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = NULL;

    ElemType x;
    scanf("%d", &x);
    LNode *p;
    while(x != 9999) {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
        scanf("%d", &x);
    }
    return L;
}

LinkList LinkedListCreatTailInsert(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    L->data = NULL;
    LNode *s; LNode *p; p = L;

    ElemType x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        p->next = s;
        p = s;
        scanf("%d", &x);
    }
    p->next = NULL;
    return L;
}

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
    } else {
        e = NULL;
    }
}
void GetElemNode(LinkList L, int i, LinkList &e) {
    LNode *p;
    p = L; // ???玄学 头结点的问题吗
    int cou = 1;
    while (p != NULL && cou < i) {
        p = p->next;
        cou++;
    }
    if (cou == i) {
        e = p;
    } else {
        e = NULL;
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
    if (p == NULL) {
        return 0;
    }
    if (p->data == e) {
        return cou;
    }
    return 0;
}

// Function8: Return the prior element of cur_e in the list
int PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e) {
    LNode *q;
    q = L;
    while (q->next->data != cur_e) {
        q = q->next;
    }
    pre_e = q->data;
    return pre_e;
}
void PriorElemNode(LinkList L, ElemType cur_e, LinkList &pre_e) {
    LNode *q;
    q = L;
    while (q->next->next->data != cur_e) {
        q = q->next;
    }
    pre_e = q;
}

// Function9: Return the next element of cur_e in the list
int NextElem(LinkList L, ElemType cur_e, ElemType &next_e) {
    LNode *q;
    q = L->next;
    while (q->data != cur_e && q != NULL) {
        q = q->next;
    }
    if (q->next == NULL) {
        cout << "NULL";
    }
    next_e = q->next->data;
    return next_e;
}

// Function10: Insert element e at position i


bool ListInsert(LinkList &L, ElemType i, ElemType e) {
    LNode *p = L;
    for (int cou = 0; cou < i - 1 && p; ++cou) {
        p = p->next;
    }
    
    LNode *q = new LNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
    

}
//     LNode *p;
//     p = L->next;
//     int cou = 1;
//     while (cou < i && p != NULL) {
//         cou++;
//         p = p->next;
//     }
//     if (cou != i || p == NULL) {
//         return false;
//     }
//     LNode *pNew;
//     InitList(pNew);
//     if (NULL == pNew) {
//         printf("Error in dynamic memory allocating");
//     }
//     pNew->data = e;

//     LNode *q;
//     q = L;
//     while (q->next != p) {
//         q = q->next;
//     }
//     q->next = pNew;
//     pNew->next = p;
//     return true;
// }
// 修改为下面来解决在位置1插入的问题，但受到函数6影响
//    LNode *pre_node;
//    GetElemNode(L, i, pre_node);
//    LNode *pNew;
//    InitList(pNew);
//    pNew->data = e;
//
//    pNew->next = pre_node->next;
//    pre_node->next = pNew;


// Function11: Delete element e at location i and return itself
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

    q->next = p->next; // 只有1位的玄学
    e = p->data;
    delete p;
    return e;
}

// Function12: List all of the elements
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


#endif