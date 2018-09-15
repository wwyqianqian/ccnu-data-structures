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


// Function2: Destroy the List
void DestroyList(List &L) {
    delete[] L.elem;
    L.length = 0;
    L.listSize = 0;
}


// Function3: Clear the existing List
void ClearList(List &L) {
    L.length = 0;
}


// Function4: Return TRUE if the List is empty
bool ListEmpty(List L) {
    if (0 == List.length) {
        return TRUE;
    } else {
        return FALSE;
    }
}


// Function5: Return the number of elements
int ListLength(List L) {
    return L.length;
}


// Function6: Return the i'th value as e
int GetElem(List L, int i, ElemType &e) {
    if (i >= 1 && i <= L.length) {
        e = L.elem[i - 1];
        return e;
    }
}


// Function7: Return the serial number in the list L of the first item whose value is equal to e. Else return 0.
int LocateElem(List L, ElemType e) {
    int i;
    for (i = 0; i < L.length; ++i) {
        if (L.elem[i] == e) {
            return i + 1;
        }
    }
    return 0;
}


// Function8: Return the prior element of cur_e in the list
int PriorElem(List L, ElemType cur_e, ElemType &pre_e) {
    int cur_e_serial = LocateElem(L, cur_e);
    if (cur_e_serial != 1) {
        return pre_e = L.elem[cur_e_serial - 2];
    } else {
        return 0;
    }
}


// Function9: Return the next element of cur_e in the list
int NextElem(List L, ElemType cur_e, ElemType &next_e) {
    int cur_e_serial = LocateElem(L, cur_e);
    if (cur_e_serial != L.length) {
        return next_e = L.elem[cur_e_serial];
    } else {
        return 0;
    }
}


// Function10: Insert element e into L.elem[i-1]
bool ListInsert(List &L, ElemType i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    if (L.length >= L.listSize) {
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++;
    return true;
}


// Function11: Delete element L.elem[i-1] and return it as e
int ListDelete(List &L, ElemType i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.elem[i - 1];
    for (int j = i; j < L.length; ++j) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return e;
}


// Function12: List all of the elements
void ListTraverse(List L) {
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
}


#endif