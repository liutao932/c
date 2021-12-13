#include"Blist.h"


static void BlistInit(BN** head) //初始化
{
	assert(head);
	BN* newnode = (BN*)malloc(sizeof(BN));
	assert(newnode);
	*head = newnode;
	newnode->prev = newnode;
	newnode->next = newnode;
}
static BN* BlistNode(BlistNodeType x)//申请节点
{
	BN* newnode = (BN*)malloc(sizeof(BN));
	assert(newnode);
	newnode->prev = newnode->next = NULL;
	newnode->data = x;
	return newnode;
}
static void BlistPushBack(BN* head, BlistNodeType x)//尾插
{
	BN* newnode = BlistNode(x);
	assert(newnode);
	BN* tail = head->prev;

	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = head;
	head->prev = newnode;
}
static void BlistPushFront(BN* head, BlistNodeType x)//头插
{
	BN* newnode = BlistNode(x);
	assert(newnode);
	BN* next = head->next;

	newnode->next = next;
	next->prev = newnode;

	head->next = newnode;
	newnode->prev = head;
}
static void BlistPopFront(BN* head)//头删
{
	assert(head && head->next);
	BN* next = head->next;
	BN* NextNext = next->next;
	if (NextNext == NULL)
	{
		next = NULL;
	}
	else
	{
		head->next = NextNext;
		NextNext->prev = head;
		free(next);
	}
}
static void BlistPopBack(BN* head)//尾删
{
	assert(head && head->next);
	BN* tail = head->prev;
	BN* prevtail = tail->prev;
	prevtail->next = head;
	head->prev = prevtail;
	free(tail);
}
static void BlistDestroy(BN* head) //销毁
{

	BN* cur = head->next;
	while (cur != head)
	{
		BN* next = cur->next;
		free(cur);
		cur = next;
	}
}
static void BlistPrint(BN* head)//打印
{
	assert(head);
	BN* next = head->next;
	while (next != head)
	{
		printf("%d->", next->data);
		next = next->next;
	}
}
static void BlistInsert(BN* Node,BlistNodeType x); //指定节点之前插入
void Blist()//总接口
{
	BN* root;
	BlistInit(&root);
	BlistPushBack(root, 10);
	BlistPushBack(root, 20);
	BlistPushBack(root, 30);
	BlistPushBack(root, 40);
	BlistPushBack(root, 50);
	BlistPrint(root);
}