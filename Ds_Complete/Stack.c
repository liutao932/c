#include"Stack.h"

static void StackInit(ST* pc) //初始化
{
	assert(pc);
	pc->a = NULL;
	pc->size = pc->capatity = 0;
}
static void StackPush(ST* pc, StackDataType x)//插入
{
	assert(pc);
	if (pc->size == pc->capatity)
	{
		int newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		StackDataType* tmp = (StackDataType*)realloc(pc->a, sizeof(StackDataType) * newcapatity);
		assert(tmp);
		pc->a = tmp;
		pc->capatity = newcapatity;
	}
	pc->a[pc->size++] = x;
}
static StackDataType StackTop(ST* pc)//取栈顶
{
	assert(pc);
	return pc->a[pc->size - 1];
}
static void StackPop(ST* pc)//弹栈
{
	assert(pc);
	pc->size--;
}
static bool StackEmpty(ST* pc)//栈是否为空
{
	assert(pc);
	return pc->size == 0;
}
static void StackDestroy(ST* pc)//销毁栈
{
	assert(pc);
	free(pc->a);
	pc->a = NULL;
	pc->size = pc->capatity;
}
static void StackPrint(ST* pc)//打印
{
	for (int i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->a[i]);
	}
	printf("\n");
}
static void StackQueue(void)//栈实现队列
{
	ST st1, st2;
	StackInit(&st1);
	StackPush(&st1, 1);
	StackPush(&st1, 2);
	StackPush(&st1, 3);
	StackPush(&st1, 4);
	StackPush(&st1, 5);
	StackInit(&st2);
	while (!StackEmpty(&st1))
	{
		StackPush(&st2, StackTop(&st1));
		StackPop(&st1);
	}
	while (!StackEmpty(&st2))
	{
		int tmp = StackTop(&st2);
		StackPop(&st2);
		printf("%d ", tmp);
	}
}
void Stack(void)//总接口
{
	/*ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPrint(&st);*/
	StackQueue();
}