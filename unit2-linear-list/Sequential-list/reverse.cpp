#include <iostream>
#include "../listFunctionHub.h"
using namespace std;

void reverse(List &LA) {
    ElemType temp;
    for (int i = 0; i < LA.length/2; ++i) {
        temp = LA.elem[i];
        LA.elem[i] = LA.elem[LA.length - i - 1];
        LA.elem[LA.length - i - 1] = temp;
    }
    ListTraverse(LA);
}

void inputElements(List &mylist) {
    InitList(mylist);
    int lslen = 0;
    cin >> lslen;
    for (int i = 1; i <= lslen; ++i) {
        mylist.length = lslen;
        int ele = 0;
        cin >> ele;
        ListInsertCreat(mylist, i, ele);
    }
}

int main() {
    List LA;
    InitList(LA);
    cout << "Input your list's length and its elements: " << endl;
    inputElements(LA);
    reverse(LA);
    return 0;
}