// 两种方法求两个集合: A，B 的并集
#include <iostream>
#include "listFunctionHub.h"
using namespace std;

// 第一种方法，在 A 后面添加 B 里面不重复的元素 
void union1(List &LA, List &LB) {	
    int La_len = ListLength(LA); 
    while (!ListEmpty(LB)) { 
    	ElemType e = 0;
        ListDelete(LB, 1, e); 
        if (!LocateElem(LA, e)) { 
            ListInsert(LA, ++La_len, e); 
        }
    }
    ListTraverse(LA);
    DestroyList(LB); 
}

// 第二种方法，建立新的 E 顺序表，CD 保持不动
void union2(List LC, List LD, List &LE) {  
    int Lc_len = ListLength(LC);
    ElemType e = 0; 

    for (int i = 1; i <= Lc_len; ++i) { // 把 C 拷贝到 E
    	GetElem(LC, i, e);	
    	ListInsert(LE, i, e);  	
    } 
    int Ld_len = ListLength(LD);
    int Le_len = ListLength(LE);
    for (int i = 1; i <= Ld_len; ++i) {
        GetElem(LD, i, e);
        if (LocateElem(LE, e)) { 
	    	continue;
	    } else {
        	ListInsert(LE, ++Le_len, e);
        }
    }
    ListTraverse(LE);
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
	List LA, LB, LC, LD, LE;
	InitList(LE);
    
    printf("Input your list LA's length plz : ");
	inputElements(LA);
	printf("Input your list LB's length plz : ");
	inputElements(LB);
    printf("This is LA: ");
	ListTraverse(LA);
	printf("This is LB: ");
	ListTraverse(LB);
    printf("\033[43;30mNow let's print LA + LB: \033[0m");
	union1(LA, LB);

	printf("-------- Good job! Why not try another method? --------\n");
	printf("Input your list LC's length plz : ");
	inputElements(LC);
	printf("Input your list LD's length plz : ");
    inputElements(LD);
    printf("This is LC: ");
	ListTraverse(LC);
	printf("This is LD: ");
	ListTraverse(LD);
	printf("\033[43;30mNow let's print LE which is LA + LB: \033[0m");
    union2(LC, LD, LE);
    printf("And LC LD are still themselves: \n");
    printf("This is LC: ");
	ListTraverse(LC);
	printf("This is LD: ");
	ListTraverse(LD);
   
    return 0;
}
