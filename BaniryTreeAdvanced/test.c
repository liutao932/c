#include"banirytree.h"
#include"queue.h"

void test()
{
	BTNode* root = NULL;
	BTNodeCreat(&root);
	BTNodePrint(root);
	printf("\n BTNodeSize::%d", BTNodeSize(root));
	printf("\nBTNodeSizeLeaf::%d", BTNodeSizeLeaf(root));
	printf("\nBTNodeSizeK::%d", BTNodeSizeK(root, 3));
	printf("\nBTNodeDeth::%d", BTNodeDeth(root));
	BTNode* newnode = BTNodeFind(root, 'B');
	printf("\nBTNodeFind::%c", newnode->data);
	printf("\nBTNodeFind->LeftChild->data::%c", newnode->LeftChild->data);
	printf("\nBTNodeFind->RigthChild->data::%c", newnode->RigthChild->data);
}

void BaniryTreeStack(BTNode* root)
{
	struct Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		printf("%c ", tmp->data);
		QueuePop(&q);
		//带孩子入队列
		if (tmp->LeftChild)
		{
			QueuePush(&q, tmp->LeftChild);
		}
		if (tmp->RigthChild)
		{
			QueuePush(&q, tmp->RigthChild);
		}
	}
	QueueDestroy(&q);
}
void test2()
{
	BTNode* root = NULL;
	BTNodeCreat(&root);
	BaniryTreeStack(root);
}
int main()
{
	//test();
	test2();
}