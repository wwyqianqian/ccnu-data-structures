#include <iostream>
using namespace std;
const int MAXSIZE = 20;

typedef struct {
    RcdType r[MAXSIZE + 1]; // r[0] 闲置作为哨兵
    int length;
} SqList;

typedef int KeyType; // 关键字类型
typedef struct {
    KeyType key; // 关键字项
    InfoType otherInfo; // 其他数据项
} RcdType;


// 3.2.2 简单排序：起泡排序
void BubbleSort(SqList &L) {
    RcdType W;
    i = L.length;
    while (i > 1) { // 大于 1 就是上一次进行过了交换，不能跳出循环哦 ><
        lastExchangeIndex = 1; // 迫真哨兵
        for (int j = 1; j < i; ++j) {
            if (L.r[j + 1].key < L.r[j].key) {
                W = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = W;
                lastExchangeIndex = j;
            }
        }
        i = lastExchangeIndex; // 一趟中最后一次交换完成的位置
    }
}


// 3.2.1 简单排序：插入排序
void InsertSort(SqList &L) {
    for (int i = 2; i <= L.length; ++i) { // 从下标 2 开始比较
        if (L.r[i].key < L.r[i - 1].key) {
            L.r[0] = L.r[i]; // 复制为哨兵
            for (j = i - 1; L.r[0].key < L.r[j].key; --j) {
                L.r[j + 1] = L.r[j];
            }
            L.r[j + 1] = L.r[0];
        }
    }
}


// 3.1 简单排序：选择排序
void SelectSort(SqList &L) {
    RcdType W;
    for (int i = 1; i < L.length; ++i) {
        j = i;
        for (int k = i + 1; k <= L.length; ++k) {
            if (L.r[k].key < L.r[j].key) {
                j = k;
            }
        }
        if (i != j) {
            W = L.r[j];
            L.r[j] = L.r[i];
            L.r[i] = W;
        }
    }
}


