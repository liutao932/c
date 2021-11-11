#include"banirytree.h"


void test()
{
	BTNode* root = NULL;
	BTNodeCreat(&root);
	BTNodePrint(root);
	printf("\n%d", BTNodeSize(root));
	printf("\n%d", BTNodeSizeLeaf(root));
	printf("\n%d", BTNodeSizeK(root, 3));
	printf("\n%d", BTNodeDeth(root));
	BTNode* newnode = BTNodeFind(root, 'B');
	printf("\n%c", newnode->data);
	printf("\n%c", newnode->LeftChild->data);
	printf("\n%c", newnode->RigthChild->data);
}
int main()
{
	test();
}