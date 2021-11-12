#include"banirytree.h"


BTNode* BuyNode(BaniryTreeData x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->data = x;
	newnode->LeftChild = newnode->RigthChild = NULL;
	return newnode;
}
void BTNodeCreat(BTNode** root)
{
	BTNode* NodeA = BuyNode('A');
	*root = NodeA;
	BTNode* NodeB = BuyNode('B');
	BTNode* NodeC = BuyNode('C');
	BTNode* NodeD = BuyNode('D');
	BTNode* NodeE = BuyNode('E');
	BTNode* NodeF = BuyNode('F');
	BTNode* NodeG = BuyNode('G');
	BTNode* NodeH = BuyNode('H');
	BTNode* NodeJ = BuyNode('J');
	NodeA->LeftChild = NodeB;
	NodeA->RigthChild = NodeC;
	NodeB->LeftChild = NodeD;
	NodeB->RigthChild = NodeE;
	NodeC->LeftChild = NodeF;
	NodeC->RigthChild = NodeG;
	NodeE->LeftChild = NodeH;
	NodeF->LeftChild = NodeJ;
}
void BTNodePrint(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BTNodePrint(root->LeftChild);
	BTNodePrint(root->RigthChild);
}

int BTNodeSize(BTNode* root)
{
	return root == NULL ? 0 : BTNodeSize(root->LeftChild) + BTNodeSize(root->RigthChild) + 1;
}

int BTNodeSizeLeaf(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->LeftChild == NULL && root->RigthChild == NULL)
	{
		return 1;
	}
	return BTNodeSizeLeaf(root->LeftChild) + BTNodeSizeLeaf(root->RigthChild);
}

int BTNodeSizeK(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BTNodeSizeK(root->LeftChild, k - 1) + BTNodeSizeK(root->RigthChild, k - 1);
}

int BTNodeDeth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftdeth = BTNodeDeth(root->LeftChild);
	int rigthdeth = BTNodeDeth(root->RigthChild);
	return leftdeth > rigthdeth ? leftdeth + 1 : rigthdeth + 1;
}
BTNode* BTNodeFind(BTNode* root, BaniryTreeData x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* leftnode = BTNodeFind(root->LeftChild, x);
	if (leftnode)
	{
		return leftnode;
	}
	BTNode* rigthnode = BTNodeFind(root->RigthChild, x);
	if (rigthnode)
	{
		return rigthnode;
	}
	return NULL;
}