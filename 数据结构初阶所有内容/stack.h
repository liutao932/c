#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//struct BaniryTreeNode;
//typedef struct BaniryTreeNode* StackDataType;
typedef int StackDataType;
typedef struct Stack
{
	StackDataType* a;
	int top;
	int capatity;
}S;

void StackInit(S* pc);
void StackPush(S* pc, StackDataType x);
void StackPop(S* pc);
StackDataType StackTop(S* pc);
bool StackEmpty(S* pc);
void StackDestroy(S* pc);
void StackPrint(S* pc);