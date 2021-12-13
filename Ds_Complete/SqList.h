#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
typedef int SqListDataType;

typedef struct SqList
{
	SqListDataType* a;
	int size;
	int capatity;
}SQ;
extern void SqListInit(SQ* pc); //初始化
extern void SqListPushBack(SQ* pc, SqListDataType x); //尾插
extern void SqListPushFront(SQ* pc, SqListDataType x);//头插
extern void SqListPopBack(SQ* pc);//尾删
extern void SqListPopFront(SQ* pc);//头删
extern bool SqListEmpty(SQ* pc);//是否为空
extern void SqListPrint(SQ* pc);//打印
extern void SqListDestroy(SQ* pc); //销毁
extern SqListDataType* SqListDifferentTwoNumber(SQ* pc, SqListDataType* returnSize);//找到数组中两个不相同的数
extern SqListDataType SqListOnlyNumber(SQ* pc);//找数组中唯一一个不是成对出现的数字的
extern void SqList(); //总接口