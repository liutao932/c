#include"queue.h"


struct QueueNode* QueueBuyNode(QueueDataType x)//申请节点
{
	struct QueueNode* newnode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void QueueInit(struct Queue* q) //初始化
{
	assert(q);
	q->head = q->tail = NULL;
}
void QueuePush(struct Queue* q, QueueDataType x) //入队
{
	assert(q);
	struct QueueNode* newnode = QueueBuyNode(x);
	if (q->tail == NULL)
	{
		q->head = q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
}
void QueuePop(struct Queue* q)//出队
{
	assert(q);
	assert(!QueueEmpty(q));
	if (q->head == q->tail)
	{
		q->head = q->tail = NULL;
	}
	else
	{
		struct QueueNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
}
QueueDataType QueueFront(struct Queue* q)//取对头
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->head->data;
}
QueueDataType QueueBehind(struct Queue* q)//取队尾
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->tail->data;
}
bool QueueEmpty(struct Queue* q)//判断是否为空
{
	assert(q);
	return q->head == NULL;
}
void QueueDestroy(struct Queue* q)//销毁队列
{
	assert(q);
	while (q->head != NULL)
	{
		struct QueueNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
}