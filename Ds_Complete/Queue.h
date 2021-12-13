#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QueueDataType;
typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QN;

typedef struct Queue
{
	QN* head;
	QN* tail;
	QueueDataType size;
}QU;

extern void QueueInit(QU* pc);//初始化
extern QN* QueueBuyNode(QueueDataType x);//申请节点
extern void QueuePush(QU* pc, QueueDataType x);//入队
extern QueueDataType QueueTop(QU* pc);//取对头
extern QueueDataType QueueBack(QU* pc);//取队尾
extern void QueuePop(QU* pc);//出队
extern QueueDataType QueueEmpty(QU* pc);//队列是否为空
extern void QueueDestroy(QU* pc);//队列销毁
extern void QueuePrint(QU* pc);//打印
extern void Queue(void);//总接口