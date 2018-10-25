#include <iostream>
#include "listFunctionHub.h"
#define MAX_NUM_OF_KEY 2 // 关键字项数最大值
#define RADIX 10 // 基数
#define MAXSIZE 1000
using namespace std;


typedef struct {
    int keys[MAX_NUM_OF_KEY];
    // 暂时用不到 所以注释掉了
    // string name, id;

    int bitsnum; // 关键字位数 应该是 bitsnum (位数), 不是 bitsum (位和)
} RcdType;

void RadixPass(RcdType A[], RcdType B[], int n, int i);

RcdType elemToRcd(ElemType elem) { //把 elem 转成 RcdType
    RcdType rcd;
    rcd.bitsnum = MAX_NUM_OF_KEY;
    rcd.keys[0] = elem / 10; // 十位
    rcd.keys[1] = elem % 10; // 个位
    return rcd;
}

void RadixSort(List &L) {
    RcdType C[L.length];
    RcdType LCopy[L.length]; // 一个用来储存 L 的 elem[] 的 RcdType[]，也就是伪码里的 L.r （精神 L.r(((

    int i;
    for ( i = 0; i < L.length; ++i) { // 把 L 的 elem[] 写进 LCopy[]
        LCopy[i] = elemToRcd(L.elem[i]);
    }
    
    i = MAX_NUM_OF_KEY - 1;
    while (i >= 0) {
        RadixPass(LCopy, C, L.length, i); // L.r 改成 LCopy
        i--;
        if (i >= 0) {
            RadixPass(C, LCopy, L.length, i); // L.r 改成 LCopy
            i--;
        } else {
            for (int j = 0; j < L.length; ++j) {
                LCopy[j] = C[j]; // 把整理好的 C 写进 LCopy
            }
        }
    }

    for (int j = 0; j < L.length; ++j) { // 把 LCopy 写回 L
        L.elem[j] = LCopy[j].keys[0] * 10 + LCopy[j].keys[1];
    }
}

void RadixPass(RcdType A[], RcdType B[], int n, int i) {
    int count[RADIX];
    for (int j = 0; j < RADIX; ++j) {
        count[j] = 0;
    }
    for (int k = 0; k < n; ++k) {
        count[A[k].keys[i]]++;
    }
    for (int j = 1; j < RADIX; ++j) {
        count[j] = count[j - 1] + count[j];
    }
    for (int k = n - 1; k >= 0; --k) {
        int j = A[k].keys[i];
        B[count[j] - 1] = A[k];
        count[j]--;
    }
}


int main() {
    List list;
    InitList(list);

    int count = 15; // 填充计数器

    /*
     * 填充 15 次，用 rand() % 100 来保证每次写入的都是两位数
     * 然后 rand()好像如果不加初始位移的话每次都会从同一张随机数表来读取，所以其实我这里每次生成的是一样的
    */
    while (count >=0 && ListInsert(list, 1, rand() % 100)) count--;
    
    ListTraverse(list); // 输出排序之前的 list
    RadixSort(list);
    ListTraverse(list); // 输出排序之后的 list
    cout << "qqjy" << endl;
    return 0;
}