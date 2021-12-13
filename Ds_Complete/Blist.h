#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int BlistNodeType;

typedef struct BlistNode
{
	BlistNodeType data;
	struct BlistNode* prev;
	struct BlistNode* next;
}BN;

extern void BlistInit(BN** head); //初始化
extern BN* BlistNode(BlistNodeType x);//申请节点
extern void BlistPushBack(BN* head, BlistNodeType x);//尾插
extern void BlistPushFront(BN* head, BlistNodeType x);//头插
extern void BlistPopFront(BN* head);//头删
extern void BlistPopBack(BN* head);//尾删
extern void BlistDestroy(BN* head); //销毁
extern void BlistInsert(BN* Node,BlistNodeType x); //指定节点之前插入
extern void BlistPrint(BN* head);//打印
extern void Blist();//总接口