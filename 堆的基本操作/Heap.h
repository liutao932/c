#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int  HeapDataType;
typedef struct Heap
{
	HeapDataType *a;
	int size;
	int capatity;
}HP;
void HeapInit(HP* pc);
void HeapPush(HP* pc, HeapDataType x);
void HeadDestory(HP* pc);
HeapDataType HeapTop(HP* pc);
void HeapPop(HP* pc);
bool HeapEmpty(HP* pc);
void HeapPrint(HP* pc);