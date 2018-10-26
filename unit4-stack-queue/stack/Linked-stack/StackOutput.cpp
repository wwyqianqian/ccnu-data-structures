#include <iostream>
#include "linkedStackWithoutHeadFunHub.h"
using namespace std;

//int A[5] = {1, 2, 3, 4, 5};
//int B[5] = {4, 5, 3, 2, 1}; // 1
//int B[5] = {4, 3, 5, 1, 2}; // 0
//int B[5] = {1, 2, 3, 4, 5}; // 1

bool solution(LinkStack &Sa, int A[], int B[]) {
    int j = 0;
    int e, q;
    for (int i = 0; i < 5; ++i) {
        Push(Sa, A[i]);

        GetTop(Sa, e);
        while (!StackEmpty(Sa) && e == B[j]) {
            Pop(Sa, q);
            // ++j;
            // ↑此处以后需要一个防止 j 超过 5 导致访问 B 的时候越界的保险栓
            // 虽然本程序逻辑种并不会碰上这种情况（因为 Sa 里最多只会有5个元素，而且只有在 Sa 非空的情况下才会进行比较并 ++j，所以 j 最大也只会到达 4)，但还是加上的好
            // 原始写法是把 ++j; 和 if (j >= 5) break; 分开写，想了一下发现可以合并成下面这行
            if (++j >= 5) break;

            // 让 e 等于新的栈顶，再次参与比较，这样 while 就有意义了
            // 不然 e 不变的情况下，j++ 以后，新的 B[j] 肯定不会还和 e 相等了，就没必要用 while 循环了，用 if 就好
            // 但是用 if 的话，就没法保证在五次循环以后 Sa 就能空掉(因为每个循环内最多 pop 一次，也可能不 pop)
            // 这也是之前的版本 i>=5 的时候还需要再循环几次来 GetTop 并进行判断的原因
            GetTop(Sa, e); 
        }
    }
    return StackEmpty(Sa);
}

int main(void) {
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
