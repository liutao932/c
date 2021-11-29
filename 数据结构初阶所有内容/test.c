#include"list.h"
#include"sqlist.h"
#include"dlist.h"
#include"stack.h"
#include"queue.h"
#include"banirytree.h"
#include"sort.h"
void ListTest()
{
	LN* root = NULL;
	ListPushFront(&root, 1);
	ListPushFront(&root, 2);
	ListPushFront(&root, 3);
	ListPushFront(&root, 4);
	ListPushFront(&root, 5);
	ListPushTail(&root, 10);
	ListPushTail(&root, 20);
	ListPushTail(&root, 30);
	ListPushTail(&root, 40);
	ListPushTail(&root, 50);
	ListPrint(root);
	LN * n1 = ListReverse(root);
	ListPrint(n1);
	ListDestroy(&n1);
}
void SqListTest()
{
	SL st;
	SqListInit(&st);
	SqListPushTail(&st, 1);
	SqListPushTail(&st, 2);
	SqListPushTail(&st, 3);
	SqListPushTail(&st, 4);
	SqListPushTail(&st, 5);
	SqListPushFront(&st, 10);
	SqListPushFront(&st, 20);
	SqListPushFront(&st, 30);
	SqListPushFront(&st, 40);
	SqListPushFront(&st, 50);
	SqListPopTail(&st);
	SqListPopTail(&st);
	SqListPopTail(&st);
	SqListPopTail(&st);
	SqListPopTail(&st);
	SqListPopFront(&st);
	SqListPopFront(&st);
	SqListPopFront(&st);
	SqListPopFront(&st);
	SqListPopFront(&st);
	SqListPrint(&st);
	SqListDestroy(&st);
}
void DlistTest()
{
	DN* root = NULL;
	DlistInit(&root);
	DlistPushFront(root, 1);
	DlistPushFront(root, 2);
	DlistPushFront(root, 3);
	DlistPushFront(root, 4);
	DlistPushFront(root, 5);
	DlistPushTail(root, 10);
	DlistPushTail(root, 20);
	DlistPushTail(root, 30);
	DlistPushTail(root, 40);
	DlistPushTail(root, 50);
	DlistPopFront(root);
	DlistPopFront(root);
	DlistPopFront(root);
	DlistPopFront(root);
	DlistPopFront(root);
	DlistPopTail(root);
	DlistPopTail(root);
	DlistPopTail(root);
	DlistPopTail(root);
	DlistPopTail(root);
	DlistPrint(root);
}
//void StackTest()
//{
//	S st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	StackPush(&st, 5);
//	StackPop(&st);
//	StackPop(&st);
//	StackPop(&st);
//	StackPop(&st);
//	StackPop(&st);
//	StackPrint(&st);
//	StackDestroy(&st);
//}
//void QueueTest()
//{
//	Q q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	QueuePush(&q, 5);
//	QueuePop(&q);
//	//QueuePrint(&q);
//	while (!QueueEmpty(&q))
//	{
//		printf("%d->", QueueFront(&q));
//		QueuePop(&q);
//	}
//	QueueDestroy(&q);
//}


void BaniryTreeTest()
{
	BT* root;
	BaniryTreeInit(&root);
	BaniryPrintFront(root);
	printf("\n");
	BaniryPrintMid(root);
	printf("\n");
	BaniryPrintBehind(root);
	printf("\n");
	printf("%d\n", BaniryTreeSize(root));
	printf("%d\n", BaniryTreeSizeLeaf(root));
	printf("%d\n", BaniryTreeSizeK(root,2));
	printf("%d\n", BaniryTreeDeth(root));
	BaniryStackPrint(root);
}
void InsetTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	InsertSort(a, 10);
	SortPrint(a, 10);
}
void ShellTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	ShellSort(a, 10);
	SortPrint(a, 10);
}
void HeapTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	HeapSort(a, 10);
	SortPrint(a, 10);
}
void SeletcTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	SeletcSort(a, 10);
	SortPrint(a, 10);
}
void BubbleTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	BubbleSort(a, 10);
	SortPrint(a, 10);
}
void QuickRTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	QuickSortR(a, 0, 9);
	SortPrint(a, 10);
}
void QuickNoRTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	QuickSortNoR(a, 0, 9);
	SortPrint(a, 10);
}
void MergreTest()
{
	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	//MergeSortR(a, 10);
	MergeSortNoR(a, 10);
	SortPrint(a, 10);
}
void CountTest()
{

	int a[10] = { 9,7,1,3,2,4,8,6,5,0 };
	CountSort(a,10);
	SortPrint(a, 10);
}
void SortTest()
{
	InsetTest();
	ShellTest();
	SeletcTest();
	HeapTest();
	BubbleTest();
	QuickRTest();
	QuickNoRTest();
	MergreTest();
	CountTest();
}
int main()
{
	//SqListTest();
	//ListTest();
	//DlistTest();
	//StackTest();
	//QueueTest();
	//BaniryTreeTest();
	SortTest();

}