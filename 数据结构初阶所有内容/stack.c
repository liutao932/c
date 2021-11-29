#include"stack.h"


void StackInit(S* pc)
{
	pc->a = NULL;
	pc->capatity = pc->top = 0;
}
void StackPush(S* pc, StackDataType x)
{
	assert(pc);
	if (pc->capatity == pc->top)
	{
		int newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		StackDataType* tmp = (StackDataType*)realloc(pc->a, sizeof(StackDataType) * newcapatity);
		assert(tmp);
		pc->a = tmp;
		pc->capatity = newcapatity;
	}
	pc->a[pc->top++] = x;
}
void StackPop(S* pc)
{
	assert(pc);
	assert(!StackEmpty(pc));
	pc->top--;
}
StackDataType StackTop(S* pc)
{
	assert(pc);
	assert(!StackEmpty(pc));
	return pc->a[pc->top - 1];
}
bool StackEmpty(S* pc)
{
	assert(pc);
	return pc->top == 0;
}
void StackDestroy(S* pc)
{
	assert(pc);
	free(pc->a);
	pc->a = NULL;
}
//void StackPrint(S* pc)
//{
//	assert(pc);
//	int i = 0;
//	for (i = 0; i < pc->top; i++)
//	{
//		printf("%c ", pc->a[i]);
//	}
//	printf("\n");
//}