#include"queue.h"

QN* QueueBuyNode(QueueDataType x)
{
	QN* newnode = (QN*)malloc(sizeof(QN));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void QueueInit(Q* pc)
{
	assert(pc);
	pc->head = pc->tail = NULL;
}
void QueuePush(Q* pc, QueueDataType x)
{
	assert(pc);
	QN* newnode = QueueBuyNode(x);
	if (pc->head == NULL)
	{
		pc->head = pc->tail = newnode;
	}
	else
	{
		pc->tail->next = newnode;
		pc->tail = newnode;
	}
}
void QueuePop(Q* pc)
{
	assert(pc);
	assert(!QueueEmpty(pc));
	if (pc->head->next == NULL)
	{
		pc->head = pc->tail = NULL;
	}
	else
	{
		QN* next = pc->head->next;
		free(pc->head);
		pc->head = next;
	}
}
QueueDataType QueueFront(Q* pc)
{
	assert(pc);
	assert(!QueueEmpty(pc));
	return pc->head->data;
}
QueueDataType QueueTail(Q* pc)
{
	assert(pc);
	assert(!QueueEmpty(pc));
	return pc->tail->data;
}
bool QueueEmpty(Q* pc)
{
	assert(pc);
	return pc->head == NULL;
}
void QueueDestroy(Q* pc)
{
	assert(pc);
	QN* cur = pc->head;
	while (cur)
	{
		QN* next = cur->next;
		free(pc->head);
		pc->head = next;
	}
}
//void QueuePrint(Q* pc)
//{
//	assert(pc);
//	QN* cur = pc->head;
//	while (cur)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//}