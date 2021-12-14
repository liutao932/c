#include"BaniryTree.h"

static void BaniryTreeNodeInit(BTN** root)//初始化
{
	BTN* NodeA = BaniryTreeBuyNode('A');
	*root = NodeA;
	BTN* NodeB = BaniryTreeBuyNode('B');
	BTN* NodeC = BaniryTreeBuyNode('C');
	BTN* NodeD = BaniryTreeBuyNode('D');
	BTN* NodeE = BaniryTreeBuyNode('E');
	NodeA->left = NodeB;
	NodeA->rigth = NodeC;
	NodeB->left = NodeD;
	NodeD->left = NodeE;
}
static BTN* BaniryTreeBuyNode(BaniryTreeData x)//申请节点
{
	BTN* newnode = (BTN*)malloc(sizeof(BTN));
	assert(newnode);
	newnode->data = x;
	newnode->left = newnode->rigth = NULL;
	return newnode;
}
static void BaniryTreePrint(BTN* root)//遍历
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BaniryTreePrint(root->left);
	BaniryTreePrint(root->rigth);
}
static int  BaniryTreeSizeNode(BTN* root)//节点的个数
{
	return root == NULL ? 0 : BaniryTreeSizeNode(root->left) + BaniryTreeSizeNode(root->rigth) + 1;
}
static int  BaniryTreeSizeKNode(BTN* root,int k)//第k层的节点的个数
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BaniryTreeSizeKNode(root->left,k -1) + BaniryTreeSizeKNode(root->rigth,k-1);
}
static int  BaniryTreeSizeLeaf(BTN* root)//叶子节点的个数
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->rigth == NULL)
		return 1;
	return BaniryTreeSizeLeaf(root->left) + BaniryTreeSizeLeaf(root->rigth);
}
static int  BaniryTreeDeth(BTN* root)//二叉树的深度
{
	if (root == NULL)
		return 0;
	int leftdeth = BaniryTreeDeth(root->left);
	int rigthdeth = BaniryTreeDeth(root->rigth);
	return leftdeth > rigthdeth ? leftdeth + 1 : rigthdeth + 1;
}
static BTN* BaniryTreeFindNode(BTN* root, BaniryTreeData x)//查找二叉树的节点
{
	if (root->data == x)
		return root;
	BTN* leftnode = BaniryTreeFindNode(root->left, x);
	if (leftnode)
	{
		return leftnode;
	}
	BTN* rigthnode = BaniryTreeFindNode(root->rigth, x);
	if (rigthnode)
	{
		return rigthnode;
	}
	return NULL;
}
static void BaniryTreeStackPrint(BTN* root)//二叉树的层序遍历
{
	QU q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTN* tmp = QueueTop(&q);
		printf("%C ", tmp->data);
		QueuePop(&q);
		if (tmp->left)
		{
			QueuePush(&q, tmp->left);
		}
		if (tmp->rigth)
		{
			QueuePush(&q, tmp->rigth);
		}
	}
	QueueDestroy(&q);
}
static bool BaniryTreeComplete(BTN* root)//是否为完全二叉树
{
	QU q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTN* tmp = QueueTop(&q);
		QueuePop(&q);
		if (tmp == NULL)
		{
			break;
		}
		QueuePush(&q, tmp->left);
		QueuePush(&q, tmp->rigth);
	}
	while (!QueueEmpty(&q))
	{
		BTN* tmp = QueueTop(&q);
		QueuePop(&q);
		if (tmp == NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}
Baniry(void)//总接口
{
	BTN* root = NULL;
	BaniryTreeNodeInit(&root);
	BaniryTreePrint(root);
	printf("SizeNode: %d\n", BaniryTreeSizeNode(root));
	printf("SizeNodeK: %d\n", BaniryTreeSizeKNode(root,3));
	printf("SizeLeafNode: %d\n", BaniryTreeSizeLeaf(root));
	printf("DethBaniryTree: %d\n", BaniryTreeDeth(root));
	BaniryTreeStackPrint(root);	
}