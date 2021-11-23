#include"QuickNoR.h"
#include"stack.h"
#include"sort.h"
void QuickNoR(int* a, int left, int rigth)
{
	struct Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, rigth);
	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);
		int key = partion1(a, begin, end);
		if (end > key + 1)
		{
			StackPush(&s, key + 1);
			StackPush(&s, end);
		}
		if (begin < key - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, key - 1);
		}
	}
	PrintSort(a, 10);
	StackDestroy(&s);
}