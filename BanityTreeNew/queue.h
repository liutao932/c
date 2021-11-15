#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

struct BaniryTreeNode;
typedef struct BaniryTreeNode* HeapDataType;
struct HeapNode
{
	HeapDataType data;
	struct HeapNode* next;
};
struct Heap
{
	struct HeapNode* head;
	struct HeapNode* tail;
};
struct HeapNode* HeapBuyNode(HeapDataType x);
void HeapInit(struct Heap* q);
void HeadPush(struct Heap* q, HeapDataType x);
void HeapPop(struct Heap* q);
HeapDataType HeapFront(struct Heap* q);
HeapDataType HeapBehind(struct Heap* q);
bool HeapEmpty(struct Heap* q);
void HeapDestroy(struct Heap* q);