#include"stack.h"


void StackInit(struct Stack* pc) //初始化栈
{
	assert(pc);
	pc->a = NULL;
	pc->size = pc->capatity = 0;
}
void StackPush(struct Stack* pc, StackDataType x)//进栈
{
	assert(pc);
	if (pc->size == pc->capatity)
	{
		int newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		StackDataType* tmp = (StackDataType*)realloc(pc->a,sizeof(StackDataType) * newcapatity);
		if (tmp == NULL)
			exit(-1);
		pc->capatity = newcapatity;
		pc->a = tmp;
	}
	pc->a[pc->size++] = x;
}
void StackPop(struct Stack* pc)//弹栈
{
	assert(pc);
	if (pc->size == 0)
	{
		printf("Stack is full\n");
		exit(-1);
	}
	pc->size--;
}
StackDataType StackTop(struct Stack* pc)//取栈顶元素
{
	assert(pc);
	assert(pc->size >= 0);
	return pc->a[pc->size -1];
}
bool StackEmpty(struct Stack* pc)//判断栈是否为空
{
	assert(pc);
	return pc->size == 0;
}
void StackDestroy(struct Stack* pc)//销毁栈
{
	assert(pc);
	free(pc->a);
	pc->a = NULL;
	pc->size = pc->capatity = 0;
}