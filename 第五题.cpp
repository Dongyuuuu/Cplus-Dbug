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
	int* PostOrder;		//��׺��������
	int* InOrder;		//��׺��������
	int min_weight;		//��СȨֵ
	int len;			//����ĳ���
	int pos;
	BiTreeNode* CreatBitree(int* mid, int* last, int n);
	void PreOrder(BiTreeNode* t);
public:
	BiTree() {};
	~BiTree() {};
	void CreatTree(int n);
	void PreOrder();  //�������
	void print();
};
//��������������������������������������
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
//�ݹ齨��
BiTreeNode* BiTree::CreatBitree(int* mid, int* last, int n) {
	BiTreeNode* t;
	int i;
	if (n == 0)
		t = NULL;
	else {
		t = new BiTreeNode();
		t->weight = last[n - 1];
		//���ɸ��ڵ�
		//Ѱ����������к�����������һ��Ԫ�أ���Ԫ��Ϊ�����
		for (i = 0; mid[i] != last[n - 1]; i++);
		//����������
		//��������и��������Ϊ������
		t->LeftChild = CreatBitree(mid, last, i);
		//����������
		//��������и������ұ�Ϊ������
		t->RightChild = CreatBitree(mid + i + 1, last + i, n - i - 1);
	}
	return t;
}
//����������������������ң�
//Ѱ�����е�Ҷ�ӽ��
//Ѱ�Ҷ�����Ҷ�ӽ�����СȨֵ
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