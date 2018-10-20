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


// 3.3.2 先进排序：归并排序（分治方法）
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n) { // 把有序 SR[i..m] SR[m+1..n] 归并为有序 TR[i..n]
    for (int j = m + 1, k = i; i <= m && j <= n; ++k) {
        if(SR[i].key <= SR[j].key) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }
    while (i <= m) {
        TR[k++] = SR[i++];
    }
    while (j <= n) {
        TR[k++] = SR[j++];
    }
}
void MSort(RcdType SR[], RcdType TR1[], int s, int t) {
    RcdType TR2[n]; // 辅助空间
    if (s == t) {
        TR1[s] = SR[s];
    } else {
        m = (s + t) / 2;
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m + 1, t);
        Merge(TR2, TR1, s, m, t);ß
    }
}
void MergeSort(SqList &L) {
    MSort(L.r, L.r, 1, L.length);
}


// 3.3.1 先进排序：快速排序
int Partition(RcdType R[], int low, int high) {
    R[0] = R[low]; // 枢轴
    pivotkey = R[low].key; // 枢轴记录关键字
    while (low < high) {
        while (low < high && R[high].key >= pivotkey) {
            --high;
        }
        if (low < high) {
            R[low++] = R[high]; // 比枢轴小的记录移动到低端
        }
        while (low < high && R[low].key <= pivotkey) {
            ++low;
        }
        if (low < high) {
            R[high--] = R[low]; // 比枢轴大的记录移动到高端
        }
    }
    R[low] = R[0]; // 枢轴记录到正确位置
    return low; // 返回枢轴的位置
}
void QSort(RcdType R[], int s, int t) {
    if (s < t) { // 长度大于 1
        pivotloc = Partition(R, s, t); // 一次划分 返回枢轴位置
        QSort(R, s, pivotloc - 1); // 对低端子序列递归排序
        QSort(R, pivotloc + 1, t); // 对高端子序列递归排序
    }
}
void QuickSort(SqList &L) {
    QSort(L.r, 1, L.length);
}


// 3.4 先进排序：基数排序
//#define MAX_NUM_OF_KEY 6
//#define RADIX 10
//#define MAXSIZE 10000
typedef char InfoType;

typedef struct {
    KeysType keys[MAX_NUM_OF_KEY];
    InfoType otherItems;
    int bitSum; // 关键字的位数
} RcdType;

void RadixSort(SqList &L) {
    RcdType C[L.length]; // 同等大小辅助空间
    i = bitsum - 1;
    while (i >= 0) {
        RadixPass(L.r, C, L.length, i);
        i--;
        if (i >= 0) {
            RadixPass(C, L.r, L.length, i);
            i--;
        } else {
            for (j = 0; j < L.length; ++j) {
                L.r[j] = C[j];
            }
        }
    }
}

void RadixPass(RcdType A[], RcdType B[], int n, int i) {
    for (int j = 0; j < RADIX; ++j) {
        count[j] = 0;
    }
    for (int k = 0; k < n; ++k) {
        count[A[k].keys[i]]++;
    }
    for (j = 1; j < RADIX; ++j) {
        count[j] = count[j - 1] + count[j];
    }
    for (int k = n - 1; k >= 0; --k) {
        j = A[k].keys[i];
        B[count[j] - 1] = A[k];
        count[j]--;
    }
}