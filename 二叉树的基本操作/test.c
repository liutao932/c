#include"binary.h"


void test()
{
	BTNode* root = BuyNode('A');
	BTNodeCreat(root);
	BTNodeFront(root);
	printf("\n");
	BTNodeMid(root);
	printf("\n");
	BTNodeBehind(root);
	printf("\n");
	printf("%d\n", BTNodeSize(root));
	printf("%d\n", BTNodeSizeLeaf(root));
	printf("%d\n", BTNodeSizeK(root, 4));
	printf("%d\n", BTNodeDeth(root));
	BTNode* newnode = BTNodeFind(root, 'C');
	printf("%c\n", newnode->data);
	printf("%c\n", newnode->left->data);
	printf("%c\n", newnode->rigth->data);
}
int main()
{
	test();
}