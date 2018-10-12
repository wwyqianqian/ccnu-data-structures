// 两种方法求两个集合: A，B 的并集
#include <iostream>
#include "../linkedListWithHeadNodeFunctionHub.h"
using namespace std;


// 第二种方法，建立新的 E 顺序表，CD 保持不动
void union2(LinkList LC, LinkList LD, LinkList &LE) {
    int Lc_len = ListLength(LC);
    
    for (int i = 1; i <= Lc_len; ++i) {
        ElemType e ;// 把 C 拷贝到 E
        GetElem(LC, i, e);
        ListInsert(LE, i, e);
    }
    int Ld_len = ListLength(LD);
    int Le_len = ListLength(LE);
    for (int i = 1; i <= Ld_len; ++i) {
        ElemType e ;
        GetElem(LD, i, e);
        if (LocateElem(LE, e)) {
            continue;
        } else {
            ListInsert(LE, ++Le_len, e);
        }
    }
    ListTraverse(LE);
}

// 求两个集合的交集
void intersection(LinkList LC, LinkList LD, LinkList &LF) {
    int Lc_len = ListLength(LC);
    int Lf_len = ListLength(LF);
    ElemType e = 0;
    for (int i = 1; i <= Lc_len; ++i) {
        GetElem(LC, i, e);
        if (LocateElem(LD, e)) {
            ListInsert(LF, ++Lf_len, e);
        }
    }
    ListTraverse(LF);
}

// 求两个集合的差集
void  differenceSet(LinkList LC, LinkList LD, LinkList &LG) {
    int Lc_len = ListLength(LC);
    ElemType e = 0;
    for (int i = 1; i <= Lc_len; ++i) { // 把 C 拷贝到 G
        GetElem(LC, i, e);
        ListInsert(LG, i, e);
    }

//    int Ld_len = ListLength(LD);
    int Lg_len = ListLength(LG);
    for (int i = 1; i <= Lg_len; ++i) {
        GetElem(LC, i, e);
        if (LocateElem(LD, e)) {
            ListDelete(LG, LocateElem(LG, e), e);
        }
    }
    ListTraverse(LG);
}




int main() {
    LinkList LC, LD, LE, LF, LG, LH;
    InitList(LE); InitList(LF); InitList(LG); InitList(LH);

   
    printf("Input your list LC's length plz : ");
    LinkedListCreatTailInsert(LC);
    printf("Input your list LD's length plz : ");
    LinkedListCreatTailInsert(LD);

    printf("\033[43;30mNow let's print LE which is LA + LB: \033[0m");
    union2(LC, LD, LE);


    printf("\033[43;30mThis is the intersection of two sets LC and LD:\033[0m");
    intersection(LC, LD, LF);

    printf("\033[43;30mThis is the difference set of two set LC - LD:\033[0m");
    differenceSet(LC, LD, LG);
    printf("\033[43;30mThis is the difference set of two set LD - LC:\033[0m");
    differenceSet(LD, LC, LH);

    return 0;
}

