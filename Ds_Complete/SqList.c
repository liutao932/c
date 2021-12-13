#include"SqList.h"

static void SqListInit(SQ* pc) //初始化
{
	assert(pc);
	pc->a = NULL;
	pc->capatity = pc->size = 0;
}
static void SqListPushBack(SQ* pc, SqListDataType x) //尾插
{
	assert(pc);
	if (pc->capatity == pc->size)
	{
		int newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		SqListDataType* tmp = (SqListDataType*)realloc(pc->a, sizeof(SqListDataType) * newcapatity);
		assert(tmp);
		pc->capatity = newcapatity;
		pc->a = tmp;
	}
	pc->a[pc->size++] = x;
}
static void SqListPushFront(SQ* pc, SqListDataType x)//头插
{
	assert(pc);
	if (pc->capatity == pc->size)
	{
		size_t newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		SqListDataType* tmp = (SqListDataType*)realloc(pc->a, sizeof(SqListDataType) * newcapatity);
		assert(tmp);
		pc->capatity = newcapatity;
		pc->a = tmp;
		//memset(pc->a, 0, sizeof(SqListDataType) * newcapatity);
	}
	int end = pc->size - 1;
	for (int i = end; end >= 0; end--)
	{
		pc->a[end + 1] = pc->a[end];
	}
	pc->a[0] = x;
	pc->size++;
}
static void SqListPopBack(SQ* pc)//尾删
{
	assert(pc);
	pc->size--;
}
static void SqListPopFront(SQ* pc)//头删
{
	assert(pc);
	int begin = 1;
	for (int i = 1; i < pc->size; i++)
	{
		pc->a[begin - 1] = pc->a[begin];
	}
}
static bool SqListEmpty(SQ* pc)//是否为空
{
	assert(pc);
	return pc->size == 0;
}
static void SqListDestroy(SQ* pc) //销毁
{
	assert(pc);
	free(pc->a);
	pc->a = NULL;
	pc->size = pc->capatity = 0;
}
void SqListPrint(SQ* pc)//打印
{
	assert(pc);
	for (int i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->a[i]);
	}
	printf("\n");
}
static SqListDataType* SqListDifferentTwoNumber(SQ* pc, SqListDataType* returnSize)//找到数组中两个不相同
{
	assert(pc);
	SqListDataType* array = (SqListDataType*)malloc(sizeof(SqListDataType) * 2);
	assert(array);
	int x = 0;
	for (int i = 0; i < pc->size; i++)
	{
		x ^= pc->a[i];
	}
	int m = 0;
	while (m < 32)
	{
		if (((x >> m) & 1) == 1)
		{
			break;
		}
		else
		{
			m++;
		}
	}
	int x1 = 0, x2 = 0;
	for (int i = 0; i < pc->size; i++)
	{
		if (((pc->a[i] >> m) & 1) == 1)
		{
			x1 ^= pc->a[i];
		}
		else
		{
			x2 ^= pc->a[i];
		}
	}
	array[0] = x1;
	array[1] = x2;
	*returnSize = 2;
	return array;
}
static SqListDataType SqListOnlyNumber(SQ* pc)//找数组中唯一一个不是成对出现的数字的
{
	assert(pc);
	int x = 0;
	for (int i = 0; i < pc->size; i++)
	{
		x ^= pc->a[i];
	}
	return x;
}
void SqList() //总接口
{
	SQ q;
	SqListInit(&q);
	SqListPushBack(&q,10);
	SqListPushBack(&q,10);
	SqListPushBack(&q,30);
	SqListPushBack(&q,20);
	SqListPushBack(&q,20);
	//SqListPushBack(&q, 40);
	//SqListPushFront(&q, 1);
	//SqListPushFront(&q, 2);
	//SqListPushFront(&q, 3);
	//SqListPushFront(&q, 4);
	//SqListPushFront(&q, 5);
	/*int size = 0;
	int * array = SqListDifferentTwoNumber(&q, &size);
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", array[i]);
	}*/
	//SqListPrint(&q);
	printf("%d ", SqListOnlyNumber(&q));
}