#include"banirytree.h"


BTNode* BuyNode(BaniryTreeData x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->data = x;
	newnode->left = newnode->rigth = NULL;
	return newnode;
}
void BTNodeInit(BTNode** root)
{
	BTNode* NodeA = BuyNode('A');
	*root = NodeA;
	BTNode* NodeB = BuyNode('B');
	BTNode* NodeC = BuyNode('C');
	BTNode* NodeD = BuyNode('D');
	BTNode* NodeE = BuyNode('E');
	NodeA->left = NodeB;
	NodeA->rigth = NodeC;
	NodeB->left = NodeD;
	NodeC->rigth = NodeE;
}
void PrintFront(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	PrintFront(root->left);
	PrintFront(root->rigth);
}
int BTNodeSize(BTNode* root)
{
	return root == NULL ? 0 : BTNodeSize(root->left) + BTNodeSize(root->rigth) + 1;
}
int BTNodeSizeLeaf(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == root->rigth)
		return 1;
	return BTNodeSizeLeaf(root->left) + BTNodeSizeLeaf(root->rigth);
}
int BTNodeSizeK(BTNode* root,int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTNodeSizeK(root->left, k - 1) + BTNodeSizeK(root->rigth, k - 1);
}
int BTNodeDeth(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftdeth = BTNodeDeth(root->left);
	int rigthdeth = BTNodeDeth(root->rigth);
	return leftdeth > rigthdeth ? leftdeth + 1 : rigthdeth + 1;
}
BTNode* BTNodeFind(BTNode* root, BaniryTreeData x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* leftnode = BTNodeFind(root->left,x);
	if (leftnode)
		return leftnode;
	BTNode* rigthnode = BTNodeFind(root->rigth, x);
	if (rigthnode)
		return rigthnode;
	return NULL;
}