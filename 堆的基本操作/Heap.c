#include"Heap.h"

void HeapInit(HP* pc)
{
	assert(pc);
	pc->a = NULL;
	pc->size = pc->capatity = 0;
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustUp(int* array, int child) //向上调整
{
	assert(array);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (array[child] > array[parent])
		{
			swap(&array[child], &array[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* pc, HeapDataType x)
{
	assert(pc);
	if (pc->size == pc->capatity)
	{
		int newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(pc->a, sizeof(HeapDataType) * newcapatity);
		pc->a = tmp;
		pc->capatity = newcapatity;
	}
	pc->a[pc->size++] = x;
	AdjustUp(pc->a, pc->size - 1);
}
void HeadDestory(HP* pc)
{
	assert(pc);
	assert(pc->a);
	free(pc->a);
	pc = NULL;
}
HeapDataType HeapTop(HP* pc)
{
	assert(pc);
	assert(!HeapEmpty(pc));
	return pc->a[0];
}
void AdjustDown(int* array,int n ,int parent)
{
	assert(array);
	int child = (parent * 2) + 1;
	while (child < n)
	{
		if (array[child + 1] < array[child])
		{
			child++;
		}
		if (array[child] < array[parent])
		{
			swap(&array[child], &array[parent]);
			parent = child;
			child = (parent * 2) + 1;
		}
	}
}
void HeapPop(HP* pc)
{
	assert(pc);
	assert(pc->a);
	swap(&pc->a[0], &pc->a[pc->size - 1]);
	pc->size--;
	AdjustDown(pc->a, pc->size,0);
}
bool HeapEmpty(HP* pc)
{
	assert(pc);
	return pc->size == 0;
}
void HeapPrint(HP* pc)
{
	assert(pc);
	assert(pc->a);
	for (int i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->a[i]);
	}
	printf("\n");
}