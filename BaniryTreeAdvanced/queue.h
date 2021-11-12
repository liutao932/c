#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

struct BaniryTreeNode;
typedef struct BaniryTreeNode* QueueDataType;

struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
};
struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
};
struct QueueNode* QueueBuyNode(QueueDataType x);//申请节点
void QueueInit(struct Queue* q); //初始化
void QueuePush(struct Queue* q, QueueDataType x); //入队
void QueuePop(struct Queue* q);//出队
QueueDataType QueueFront(struct Queue* q);//取对头
QueueDataType QueueBehind(struct Queue* q);//取队尾
bool QueueEmpty(struct Queue* q);//判断是否为空
void QueueDestroy(struct Queue* q);//销毁队列