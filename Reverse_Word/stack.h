#pragma once
#ifndef DEBUG
#define DEBUG
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char StackTypeData;
typedef struct Stack
{
	StackTypeData* a;
	int size;
	int capatity;
}ST;
extern void PointInit(struct FuntionPoint* fc);
extern void StackInit(ST* pc);
extern void StackPush(ST* pc, StackTypeData x);
extern StackTypeData StackTop(ST* pc);
extern void StackPop(ST* pc);
extern bool StackEmpty(ST* pc);
extern void StackDestroy(ST* pc);
#endif // DEBUG
