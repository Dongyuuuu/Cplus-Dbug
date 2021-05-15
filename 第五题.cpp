#include <iostream>
using namespace std;

class BiTreeNode {
public:
	BiTreeNode* RightChild;
	BiTreeNode* LeftChild;
	int weight;
	BiTreeNode() :RightChild(NULL), LeftChild(NULL), weight(0) {};
	~BiTreeNode() { ; }
};
class BiTree {
	BiTreeNode* Root;
	int* PostOrder;		//后缀遍历数组
	int* InOrder;		//中缀遍历数组
	int min_weight;		//最小权值
	int len;			//数组的长度
	int pos;
	BiTreeNode* CreatBitree(int* mid, int* last, int n);
	void PreOrder(BiTreeNode* t);
public:
	BiTree() {};
	~BiTree() {};
	void CreatTree(int n);
	void PreOrder();  //先序遍历
	void print();
};
//构造二叉树，利用中序遍历，后序遍历结果建树
void BiTree::CreatTree(int n) {
	pos = 0;
	min_weight = 9999999;
	len = n;
	InOrder = new int[n];
	PostOrder = new int[n];
	for (int i = 0; i < n; i++)
		cin >> InOrder[i];
	for (int i = 0; i < n; i++)
		cin >> PostOrder[i];
	Root = CreatBitree(InOrder, PostOrder, len);
}
//递归建树
BiTreeNode* BiTree::CreatBitree(int* mid, int* last, int n) {
	BiTreeNode* t;
	int i;
	if (n == 0)
		t = NULL;
	else {
		t = new BiTreeNode();
		t->weight = last[n - 1];
		//生成根节点
		//寻找中序遍历中后序遍历的最后一个元素，该元素为根结点
		for (i = 0; mid[i] != last[n - 1]; i++);
		//构造左子树
		//中序遍历中根结点的左边为左子树
		t->LeftChild = CreatBitree(mid, last, i);
		//构造右子树
		//中序遍历中根结点的右边为右子树
		t->RightChild = CreatBitree(mid + i + 1, last + i, n - i - 1);
	}
	return t;
}
//定义先序遍历函数（根左右）
//寻找所有的叶子结点
//寻找二叉树叶子结点的最小权值
void BiTree::PreOrder(BiTreeNode* t) {
	if (t) {
		if (!t->LeftChild && !t->RightChild) {
			if (t->weight < min_weight)
				min_weight = t->weight;
		}
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}
void BiTree::PreOrder() {
	PreOrder(Root);
}
void BiTree::print() {
	cout << min_weight << endl;
}

int main()
{
	int n;
	while (cin >> n) {
		BiTree tree;
		tree.CreatTree(n);
		tree.PreOrder();
		tree.print();
	}
	return 0;
}