#include"Queue.h"


static void QueueInit(QU* pc)//初始化
{
	assert(pc);
	pc->head = pc->tail = NULL;
	pc->size = 0;
}
static QN* QueueBuyNode(QueueDataType x)//申请节点
{
	QN* newnode = (QN*)malloc(sizeof(QN));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
static void QueuePush(QU* pc, QueueDataType x)//入队
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
	pc->size++;
}
static QueueDataType QueueTop(QU* pc)//取对头
{
	assert(pc);
	return pc->head->data;
}
static QueueDataType QueueBack(QU* pc)//取队尾
{
	assert(pc);
	return pc->tail->data;
}
static void QueuePop(QU* pc)//出队
{
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
	pc->size--;
}
static QueueDataType QueueEmpty(QU* pc)//队列是否为空
{
	assert(pc);
	return pc->size == 0;
}
static void QueueDestroy(QU* pc)//队列销毁
{
	assert(pc);
	while (pc->head != NULL)
	{
		QN* next = pc->head->next;
		free(pc->head);
		pc->head = next;
	}
}
static void QueuePrint(QU* pc)//打印
{
	QN* cur = pc->head;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void Queue(void)//总接口
{
	QU q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePrint(&q);
}