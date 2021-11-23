#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int StackDataType;
struct Stack
{
	StackDataType data;
	int* a;
	int size;
	int capatity;
};
void StackInit(struct Stack* pc); //初始化栈
void StackPush(struct Stack* pc, StackDataType x);//进栈
void StackPop(struct Stack* pc);//弹栈
StackDataType StackTop(struct Stack* pc);//取栈顶元素
bool StackEmpty(struct Stack* pc);//判断栈是否为空
void StackDestroy(struct Stack* pc);//销毁栈