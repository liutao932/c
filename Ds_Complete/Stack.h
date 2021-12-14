#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int StackDataType;

typedef struct Stack
{
	int* a;
	int size;
	int capatity;
}ST;

extern void StackInit(ST* pc); //初始化
extern void StackPush(ST* pc, StackDataType x);//插入
extern StackDataType StackTop(ST* pc);//取栈顶
extern void StackPop(ST* pc);//弹栈
extern bool StackEmpty(ST* pc);//栈是否为空
extern void StackDestroy(ST* pc);//销毁栈
extern void StackPrint(ST* pc);//打印
extern void StackQueue();//栈实现队列
extern void Stack(void);//总接口
