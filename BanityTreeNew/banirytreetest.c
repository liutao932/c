#include"banirytree.h"
#include"queue.h"

void  test()
{
	BTNode* root = NULL;
	BTNodeInit(&root);
	PrintFront(root);
	printf("\nBTNodeSize : %d", BTNodeSize(root));
	printf("\nBTNodeSizeLeaf : %d", BTNodeSizeLeaf(root));
	printf("\nBTNodeSizeK : %d", BTNodeSizeK(root,3));
	printf("\nBTNodeDeth : %d", BTNodeDeth(root));
}
void PrintStack()
{
	BTNode* root = NULL;
	BTNodeInit(&root);
	struct Heap q;
	HeapInit(&q);
	HeadPush(&q,root);
	while (!HeapEmpty(&q))
	{
		BTNode* tmp = HeapFront(&q);
		printf("%c ", tmp->data);
		HeapPop(&q);
		if (tmp->left)
		{
			HeadPush(&q, tmp->left);
		}
		if (tmp->rigth)
		{
			HeadPush(&q, tmp->rigth);
		}
	}
}
bool CompleteBaniryTree()
{
	BTNode* root = NULL;
	BTNodeInit(&root);
	struct Heap q;
	HeapInit(&q);
	HeadPush(&q, root);
	while (!HeapEmpty(&q))
	{
		BTNode* tmp = HeapFront(&q);
		HeapPop(&q);
		if (tmp == NULL)
		{
			break;
		}
		else
		{
			HeadPush(&q, tmp->left);
			HeadPush(&q, tmp->rigth);
		}
	}
	while (!HeapEmpty(&q))
	{
		BTNode* tmp = HeapFront(&q);
		HeapPop(&q);
		if (tmp != NULL)
		{
			HeapDestroy(&q);
			return false;
		}
	}
	HeapDestroy(&q);
	return true;
}
int main()
{
	//test();
	PrintStack();
}
