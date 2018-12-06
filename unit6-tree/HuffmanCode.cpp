#include <iostream>
using namespace std;
typedef char **HuffmanCode; // 字符类型的二级指针，看作一个一维数组，每个成员是一个字符串

typedef struct {
	int weight;
	int lchild, rchild;
} HTNode;

typedef struct {
	HTNode *HTree;
	int root;
} HuffmanTree;

void createHuffmanTree(HuffmanTree &HT, int *w, int n) { // w 为数组
    if (n <= 1) {
    	return;
    }
    int m = 2 * n - 1; // 总共结点数目
    HTNode HT.HTree = new HTNode[m];
    for (HTNode p = HT.HTree, int i = 0; i < n; ++i, ++p, ++w) { // 初始化
    	// p[i].weight = w[i];
    	// p[i].lchild = -1;
    	// p[i].rchild = -1;
    	*p = {*w, -1, -1};
}
    for (HTNode p = HT.HTree; int i < m; ++i, ++p) { // 对没有使用的结点赋初值
    	// p[i].weight = 0;
    	// p[i].lchild = -1;
    	// p[i].rchild = -1;
    	*p = {0, -1, -1};
    }
    for (int i = n; i < m; ++i) {
    	Select(HT.HTree, i - 1, s1, s2); // 自己实现 Select 函数 
    	HT.HTree[i].lchild = s1;
    	HT.HTree[i].rchild = s2;
    	HT.HTree[i].weight = HT.HTree[s1].weight + HT.HTree[s2].weight;
    }
    HT.root = m - 1;
}

void Select(HTNode &htn, int i, int s1, int s2);

void HuffmanCoding(HuffmanTree HT, HuffmanCode &HC, int n) { // 先序遍历 HT，求得叶子结点的编码存入 HC
	Stack S; // 使用栈记录路径
	HuffmanCode HC = new (char *)[n];
	InitStack(S);
	Coding(HT, HT.root, S); // 编码函数，先序遍历二叉树
}

void Coding(HuffmanTree T, int i, Stack &S) {
	if (T.HTree) {
		if (T.HTree[i].lchild == -1 && T.HTree.rchild[i] == -1) {
			char HC[i] = new char[StackLength(S)]; // 最大编码长度为栈长
			StackCopytoArray(S, HC[i]); // 实现函数 StackCopytoArray() 从栈底到栈顶将字符复制到 HC[i] 中
		} else {
            Push(S, '0');
            Coding(T, T.HTree[i].lchild, S);
            int e;
            Pop(S, e);

            Push(S, '1');
            Coding(T, T.HTree[i].rchild, S);
            Pop(S, e);
	    }
	} 
}

void StackCopytoArray(Stack &S, char hci);



