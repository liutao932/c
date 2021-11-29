#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DlistDataTypde;

typedef struct DlistNode
{
	DlistDataTypde data;
	struct DlistNode* prev;
	struct DlistNode* next;
}DN;

void DlistInit(DN** head);
DN* DlistBuyNode(DlistDataTypde x);
void DlistPushFront(DN* head, DlistDataTypde x);
void DlistPushTail(DN* head, DlistDataTypde x);
void DlistPopFront(DN* head);
void DlistPopTail(DN* head);
void DlistDestroy(DN* head);
void DlistPrint(DN* head);