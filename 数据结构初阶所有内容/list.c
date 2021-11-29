#include"list.h"



LN* BuyNode(ListNodeDataType x)
{
	LN* newnode = (LN*)malloc(sizeof(LN));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void ListPushFront(LN** head, ListNodeDataType x)
{
	LN* newnode = BuyNode(x);
	newnode->next = *head;
	*head = newnode;
}
void ListPushTail(LN** head, ListNodeDataType x)
{
	LN* newnode = BuyNode(x);
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		LN* tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}
void ListPopFront(LN** head)
{
	assert(*head);
	LN* next = (*head) ->next;
	free(*head);
	*head = next;
}
void ListPopTail(LN** head)
{
	assert(*head);
	if ((*head)->next == NULL)
	{
		*head = NULL;
	}
	else
	{
		LN* prev = NULL;
		LN* tail = *head;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
void ListPrint(LN* head)
{
	LN* cur = head;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
LN* ListReverse(LN* head)
{
	LN* n1 = NULL;
	LN* n2 = head;
	while (n2)
	{
		LN* n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}
	return n1;
}
void ListDestroy(LN** head)
{
	assert(*head);
	LN* cur = *head;
	while (cur)
	{
	    LN* next = cur->next;
		free(cur);
		cur = next;
	}
}