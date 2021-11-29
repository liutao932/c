#include"banirytree.h"
#include"stack.h"
#include"queue.h"
BT* BaniryTreeBuyNode(BaniryTreeDataType x)
{
	BT* newnode = (BT*)malloc(sizeof(BT));
	assert(newnode);
	newnode->data = x;
	newnode->left = newnode->rigth = NULL;
	return newnode;
}
void BaniryTreeInit(BT** root)
{
	BT* newnodeA = BaniryTreeBuyNode('A');
	*root = newnodeA;
	BT* newnodeB = BaniryTreeBuyNode('B');
	BT* newnodeC = BaniryTreeBuyNode('C');
	BT* newnodeD = BaniryTreeBuyNode('D');
	BT* newnodeE = BaniryTreeBuyNode('E');
	newnodeA->left = newnodeB;
	newnodeA->rigth = newnodeC;
	newnodeB->left = newnodeD;
	newnodeC->left = newnodeE;
}
void BaniryPrintFront(BT* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BaniryPrintFront(root->left);
	BaniryPrintFront(root->rigth);
}
void BaniryPrintMid(BT* root)
{
	if (root == NULL)
		return;
	BaniryPrintFront(root->left);
	printf("%c ", root->data);
	BaniryPrintFront(root->rigth);
}
void BaniryPrintBehind(BT* root)
{
	if (root == NULL)
		return;
	BaniryPrintFront(root->left);
	BaniryPrintFront(root->rigth);
	printf("%c ", root->data);
}
int BaniryTreeSize(BT* root)
{
	return root == NULL ? 0 : BaniryTreeSize(root->left) + BaniryTreeSize(root->rigth) + 1;
}
int BaniryTreeSizeLeaf(BT* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->rigth == NULL)
		return 1;
	return BaniryTreeSizeLeaf(root->left) + BaniryTreeSizeLeaf(root->rigth);
}
int BaniryTreeSizeK(BT* root,int k)
{
	if (root == 0)
		return 0;
	if (k == 1)
		return 1;
	return BaniryTreeSizeK(root->left, k - 1) + BaniryTreeSizeK(root->rigth, k - 1);
}
int BaniryTreeDeth(BT* root)
{
	if (root == NULL)
		return 0;
	int leftdeth = BaniryTreeDeth(root->left);
	int rigthdeth = BaniryTreeDeth(root->rigth);
	return leftdeth > rigthdeth ? leftdeth + 1 : rigthdeth + 1;
}
BT* BaniryFind(BT* root)
{
	if (root == NULL)
		return NULL;
	BT * leftnode = BaniryFind(root->left);
	if (leftnode)
		return leftnode;
	BT* rigthnode = BaniryFind(root->rigth);
	if (rigthnode)
		return rigthnode;
	return NULL;
}

void BaniryStackPrint(BT* root)
{
	if (root == NULL)
		return;
	Q st;
	QueueInit(&st);
	QueuePush(&st, root);
	while (!QueueEmpty(&st))
	{
		BT* tmp = QueueFront(&st);
		printf("%c ", tmp->data);
		QueuePop(&st);
		if (tmp->left)
			QueuePush(&st, tmp->left);
		if (tmp->rigth)
			QueuePush(&st, tmp->rigth);
	}
	QueueDestroy(&st);
}
bool BabiryTreeComplete(BT* root)
{
	if (root == NULL)
		return true;
	Q st;
	QueueInit(&st);
	QueuePush(&st, root);
	while (!QueueEmpty(&st))
	{
		BT* tmp = QueueFront(&st);
		if (tmp == NULL)
		{
			break;
		}
		QueuePop(&st);
		QueuePush(&st, tmp->left);
		QueuePush(&st, tmp->rigth);
	}
	while (!QueueEmpty(&st))
	{
		BT* tmp = QueueFront(&st);
		if (tmp != NULL)
		{
			QueueDestroy(&st);
			return false;
		}
		QueuePop(&st);
	}
	QueueDestroy(&st);
	return true;
}