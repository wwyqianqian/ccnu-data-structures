#include <iostream>
#include "circularQueueFunHub.h"
using namespace std;



void YangHui(int n) {
    SqQueue Q;
    for (int i = 1; i <= n; i++) {
    	cout << " ";
    }
    

    cout << "1" << endl;
    InitQueue1(Q, n + 2);
    // InitQueue(Q);
    EnQueue(Q, 0);
    EnQueue(Q, 1);
    EnQueue(Q, 1);

    int k = 1;
    int e = 0;
    while (k < n) {
    	for (int i = 1; i <= n - k; i++) {
    		cout << " ";
    	}
    	EnQueue(Q, 0);
    	do {
    		int s = 0;
    		DeQueue(Q, s);
    		
    		GetHead(Q, e);
    		if (e) {
    			cout << e << " ";
    		} else {
    			cout << endl;
    		}
    		EnQueue(Q, s + e);
    	} while (e != 0);
    	k++;
    }
    DeQueue(Q, e);
    while (!QueueEmpty(Q)) {
    	DeQueue(Q, e);
    	cout << e << " ";
    }
}


int main () {
	int x;
	cin >> x;
	YangHui(x + 1);
	return 0;
}