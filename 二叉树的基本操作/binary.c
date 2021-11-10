#include"binary.h"

BTNode* BuyNode(BinaryNodeType x) //创建节点
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->data = x;
	newnode->left = newnode->rigth = NULL;
	return newnode;
 }
void BTNodeFront(BTNode* root) //前序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BTNodeFront(root->left);
	BTNodeFront(root->rigth);
}
void BTNodeMid(BTNode* root) //中序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BTNodeFront(root->left);
	printf("%c ", root->data);
	BTNodeFront(root->rigth);
}
void BTNodeBehind(BTNode* root) //后序遍历
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BTNodeFront(root->left);
	BTNodeFront(root->rigth);
	printf("%c ", root->data);
}
int BTNodeSize(BTNode* root) //二叉树节点的个数
{
	return root == NULL ? 0 : BTNodeSize(root->left) + BTNodeSize(root->rigth) + 1;
}
int BTNodeSizeLeaf(BTNode* root) //二叉树叶子节点的个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->rigth == NULL)
	{
		return 1;
	}
	return BTNodeSizeLeaf(root->left) + BTNodeSizeLeaf(root->rigth);
}
int BTNodeSizeK(BTNode* root, int k)//二叉树第K层的节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BTNodeSizeK(root->left, k - 1) + BTNodeSizeK(root->rigth, k - 1);
}
int BTNodeDeth(BTNode* root)//二叉树的深度
{
	if(root == NULL)
	{
		return 0;
	}
	int leftdeth = BTNodeDeth(root->left);
	int ritgthdeth = BTNodeDeth(root->rigth);
	return leftdeth > ritgthdeth ? leftdeth + 1 : ritgthdeth + 1;
}
BTNode* BTNodeFind(BTNode* root, BinaryNodeType x)//查找值为x的节点
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* leftnode = BTNodeFind(root->left, x);
	if (leftnode)
	{
		return leftnode;
	}
	BTNode* rigthnode = BTNodeFind(root->rigth, x);
	if (rigthnode)
	{
		return rigthnode;
	}
	return NULL;
}
void BTNodeCreat(BTNode * NodeA) //创建二叉树
{
	BTNode* NodeB = BuyNode('B');
	BTNode* NodeC = BuyNode('C');
	BTNode* NodeD = BuyNode('D');
	BTNode* NodeE = BuyNode('E');
	BTNode* NodeF = BuyNode('F');
	BTNode* NodeG = BuyNode('G');
	BTNode* NodeH = BuyNode('H');
	BTNode* NodeK = BuyNode('K');
	NodeA->left = NodeB;
	NodeA->rigth = NodeC;
	NodeB->left = NodeD;
	NodeB->rigth = NodeE;
	NodeC->left = NodeF;
	NodeC->rigth = NodeG;
	NodeE->rigth = NodeH;
	NodeH->rigth = NodeK;
}
