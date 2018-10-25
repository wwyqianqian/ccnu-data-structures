#include <iostream>
#include "listFunctionHub.h"
#define MAX_NUM_OF_KEY 2 // 关键字项数最大值
#define RADIX 10 // 基数
#define MAXSIZE 1000
using namespace std;


typedef struct {
    int keys[MAX_NUM_OF_KEY];
    string name, id;
    int bitsum; // 关键字位数
} RcdType;

void RadixSort(List &L) {
    RcdType C[L.length]; int i; // 辅助空间
    i = 1;
    while (i >= 0) {
        RadixPass(L.r, C, L.length, i);
        i--;
        if (i >= 0) {
            RadixPass(C, L.r, L.length, i);
            i--;
        } else {
            for (int j = 0; j < L.length; ++j) {
                L.r[j] = C[j];
            }
        }
    }
}

void RadixPass(RcdType A[], RcdType B[], int n, int i) {
    int count[100];
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
    cout << " d";
    return 0;
}