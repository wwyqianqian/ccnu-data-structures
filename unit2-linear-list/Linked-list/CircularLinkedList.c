// 循环链表
// 带表头结点的非空循环链表
tail->data == An;
tail->next->next->data == A1;

// 带表头结点的空循环单链表
H->next = H;
H != NULL;

// 首尾相连 O(n)，区别于头指针循环链表的 O(m+n)
p = tail2->next;
tail2->next = tail1->next;
tail1->next = p->next;
free(p);