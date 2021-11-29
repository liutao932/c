#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SqListData;

typedef struct SqList
{
	SqListData* a;
	int size;
	int capatity;
}SL;


void SqListCheck(SL* pc);
void SqListInit(SL* pc);
void SqListPushTail(SL* pc, SqListData x);
void SqListPushFront(SL* pc, SqListData x);
void SqListPopTail(SL* pc);
void SqListPopFront(SL* pc);
void SqListDestroy(SL* pc);
void SqListPrint(SL* pc);