#include"queue.h"

struct HeapNode* HeapBuyNode(HeapDataType x)
{
	struct HeapNode* newnode = (struct HeapNode*)malloc(sizeof(struct HeapNode));
	newnode->data = x;
	assert(newnode);
	newnode->next = NULL;
	return newnode;
}
void HeapInit(struct Heap* q)
{
	assert(q);
	q->head = q->tail = NULL;
}
void HeadPush(struct Heap* q, HeapDataType x)
{
	assert(q);
	struct HeapNode* newnode = HeapBuyNode(x);
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
void HeapPop(struct Heap* q)
{
	assert(q);
	if (q->head == q->tail)
	{
		q->head = q->tail = NULL;
	}
	else
	{
		struct HeapNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
}
HeapDataType HeapFront(struct Heap* q)
{
	assert(q);
	assert(q->head);
	return q->head->data;
}
HeapDataType HeapBehind(struct Heap* q)
{
	assert(q);
	assert(q->head);
	return q->tail->data;
}
bool HeapEmpty(struct Heap* q)
{
	assert(q);
	return q->head == NULL;
}
void HeapDestroy(struct Heap* q)
{
	assert(q);
	while (q->head != NULL)
	{
		struct HeapNode* next = q->head->next;
		free(q->head);
		q->head = next;
	}
}