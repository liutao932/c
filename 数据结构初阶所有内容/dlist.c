#include"dlist.h"


void DlistInit(DN** head)
{
	assert(head);
	DN* newnode = DlistBuyNode(-1);
	*head = newnode;
	(*head)->next = *head;
	(*head)->prev = *head;
}
DN* DlistBuyNode(DlistDataTypde x)
{
	DN* newnode = (DN*)malloc(sizeof(DN));
	assert(newnode);
	newnode->data = x;
	newnode->next = newnode->prev = NULL;
	return newnode;
}
void DlistPushFront(DN* head, DlistDataTypde x)
{
	DN* newnode = DlistBuyNode(x);
	assert(newnode);
	DN* next = head->next;

	newnode->next = next;
	next->prev = newnode;

	head->next = newnode;
	newnode->prev = head;
}
void DlistPushTail(DN* head, DlistDataTypde x)
{
	DN* newnode = DlistBuyNode(x);
	assert(newnode);
	DN* tail = head->prev;

	tail->next = newnode;
	newnode->prev = tail;

	newnode->next = head;
	head->prev = newnode;
}
void DlistPopFront(DN* head)
{
	assert(head && head->next);
	DN* next = head->next;
	DN* NextNext = next->next;
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
void DlistPopTail(DN* head)
{
	assert(head && head->next);
	DN* tail = head->prev;
	DN* prevtail = tail->prev;
	prevtail->next = head;
	head->prev = prevtail;
	free(tail);
}
void DlistDestroy(DN* head)
{
	DN* cur = head->next;
	while (cur != head)
	{
		DN* next = cur->next;
		free(cur);
		cur = next;
	}
}

void DlistPrint(DN* head)
{
	DN* cur = head->next;
	while (cur != head)
	{
		DN* next = cur->next;
		printf("%d->", cur->data);
		cur = next;
	}
}