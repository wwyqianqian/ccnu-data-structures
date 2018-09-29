#include <iostream>
#include "../listFunctionHub.h"
using namespace std;

int compare(List A, List B) {
    int j = 0;
    while (j < A.length && j < B.length) {
        if (A.elem[j] < B.elem[j]) {
            return -1;
        } else if (A.elem[j] > B.elem[j]) {
            return 1;
        } else {
            j++;
        }
    }
    if (A.length == B.length) {
        return 0;
    } else if (A.length < B.length) {
        return -1;
    } else {
        return 1;
    }
}

bool ListInsertChar(List &L, char i, char e) {
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
    return true;
}

void inputElements(List &mylist) {
    int lslen = 0;
    cin >> lslen;
    for (int i = 1; i <= lslen; ++i) {
        mylist.length = lslen;
        char ele = 0;
        cin >> ele;
        ListInsertChar(mylist, i, ele);
    }
}

int main() {
    List LA, LB;
    InitList(LA); InitList(LB);
    printf("input LA");
    inputElements(LA);
//    ListTraverse(LA);

    printf("input LB");
    inputElements(LB);
//    ListTraverse(LB);

    int com = compare(LA, LB);
    if (com == -1) {
        cout << com << " " <<  "LA < LB";
    } else if (com == 1) {
        cout << com << " " << "LA > LB";
    } else {
        cout << com << " " << "LA = LB";
    }
    return 0;

}

