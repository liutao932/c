#include "sqlist.h"
void SqListInit(SL* pc)
{
	assert(pc);
	pc->a = NULL;
	pc->size = pc->capatity = 0;
}
void SqListCheck(SL* pc)
{
	assert(pc);
	if (pc->capatity == pc->size)
	{
		int newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		SqListData* tmp = (SqListData*)realloc(pc->a, sizeof(SqListData) * newcapatity);
		assert(tmp);
		pc->a = tmp;
		pc->capatity = newcapatity;
	}
}
void SqListPushTail(SL* pc, SqListData x)
{
	assert(pc);
	SqListCheck(pc);
	pc->a[pc->size++] = x;
}
void SqListPushFront(SL* pc, SqListData x)
{
	assert(pc);
	SqListCheck(pc);
	int end = pc->size -1;
	for (int i = end; i >= 0; i--)
	{
		pc->a[i + 1] = pc->a[i];
	}
	pc->a[0] = x;
	pc->size++;
}
void SqListPopTail(SL* pc)
{
	assert(pc);
	pc->size--;
}
void SqListPopFront(SL* pc)
{
	assert(pc);
	SqListCheck(pc);
	int begin = 1;
	for (int i = begin; i < pc->size; i++)
	{
		pc->a[i - 1] = pc->a[i];
	}
	pc->size--;
}
void SqListDestroy(SL* pc)
{
	assert(pc);
	free(pc->a);
	pc->a = NULL;
}
void SqListPrint(SL* pc)
{
	assert(pc);
	for (int i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->a[i]);
	}
	printf("\n");
}