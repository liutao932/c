#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ListNodeDataType;

typedef struct ListNode
{
	ListNodeDataType data;
	struct ListNode* next;
}LN;

LN* BuyNode(ListNodeDataType x);
void ListPushFront(LN** head, ListNodeDataType x);
void ListPushTail(LN** head, ListNodeDataType x);
void ListPopFront(LN** head);
void ListPopTail(LN** head);
void ListPrint(LN* head);
LN* ListReverse(LN* head);
void ListDestroy(LN** head);