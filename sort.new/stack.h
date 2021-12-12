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

void StackInit(ST* pc); //³õÊ¼»¯Õ»
void StackPush(ST* pc, StackDataType x);//Ñ¹Õ»
StackDataType StackTop(ST* pc);//È¡Õ»¶¥ÔªËØ
void StackPop(ST* pc); //µ¯Õ»
bool StackEmpty(ST* pc);//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
void StackDestroy(ST* pc);//Ïú»ÙÕ»