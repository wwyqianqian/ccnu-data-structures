#include <iostream>
#include "linkedStackWithoutHeadFunHub.h"
using namespace std;

//int A[5] = {1, 2, 3, 4, 5};
//int B[5] = {4, 5, 3, 2, 1}; // 1
//int B[5] = {4, 3, 5, 1, 2}; // 0
//int B[5] = {1, 2, 3, 4, 5}; // 1

bool solution(LinkStack &Sa, int A[], int B[]) {
    int j = 0;
    for (int i = 0; i < 25; ++i) {
        if (i < 5) {
            Push(Sa, A[i]);
        }

        int e;
        GetTop(Sa, e);
        while (!StackEmpty(Sa) && e == B[j]) {
            int q;
            Pop(Sa, q);
            ++j;
        }
    }
    if (StackEmpty(Sa)) {
        return true;
    }
    return false;

}

int main() {
    LinkStack Sa;
    InitStack(Sa);

    int A[5] = {0};
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }
    int B[5] = {0};
    for (int j = 0; j < 5; ++j) {
        cin >> B[j];
    }
    cout << solution(Sa, A, B);

    return 0;
}


//> ./a.out
//1 2 3 4 5
//4 5 3 2 1
//1⏎
//> ./a.out
//1 2 3 4 5
//4 5 3 1 2
//0⏎
//> ./a.out
//1 2 3 4 5
//1 2 3 4 5
//1⏎