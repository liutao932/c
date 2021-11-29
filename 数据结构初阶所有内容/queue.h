#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
struct BaniryTreeNode;
typedef struct BaniryTreeNode* QueueDataType;
typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QN;

typedef struct Queue
{
	QN* head;
	QN* tail;
}Q;

QN* QueueBuyNode(QueueDataType x);
void QueueInit(Q* pc);
void QueuePush(Q* pc, QueueDataType x);
void QueuePop(Q* pc);
QueueDataType QueueFront(Q* pc);
QueueDataType QueueTail(Q* pc);
bool QueueEmpty(Q* pc);
void QueueDestroy(Q* pc);
void QueuePrint(Q* pc);