#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int StackDataType;

typedef struct Stack
{
	StackDataType* a;
	int size;
	int capatity;
}ST;

void StackInit(ST* pc); //��ʼ��ջ
void StackPush(ST* pc, StackDataType x);//ѹջ
StackDataType StackTop(ST* pc);//ȡջ��Ԫ��
void StackPop(ST* pc); //��ջ
bool StackEmpty(ST* pc);//�ж�ջ�Ƿ�Ϊ��
void StackDestroy(ST* pc);//����ջ