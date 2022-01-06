#include"Sort.h"
#include"Stack.h"

static void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
static void InsertSort(int* a, int n)//插入
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int x = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > x)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = x;
	}
}
static void ShellSort(int* a, int n)//希尔
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > x)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = x;
		}
	}
}
static void SeletcSort(int* a, int n)//选择
{
	int begin = 0, end = n - 1;
	while (begin <= end)
	{
		int min = begin, max = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[min] > a[i])
			{
				min = i;
			}
			if (a[max] < a[i])
			{
				max = i;
			}
		}
		swap(&a[min], &a[begin]);
		if (max == begin)
		{	
			max = min;
		}
		swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}
static void AdjustDown(int* a, int parent, int n)//向下
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
static void AdjustUp(int* a, int child)//向上
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
static void HeapSort(int* a, int n)//堆排
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	for (int end = n - 1; end >= 0; end--)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
	}
}
static void BubbleSort(int* a, int n)//冒泡
{
	int end = n - 1;
	int exchange = 0;
	while (end >= 0)
	{
		for (int i = 1; i <= end; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		end--;
		if (exchange == 0)
		{
			break;
		}
	}
}
int GetMid(int* a, int left, int rigth)
{
	int mid = left + ((rigth - left) >> 1);
	if (a[left] < a[rigth])
	{
		if (a[rigth] < a[mid])
			return rigth;
		else if (a[left] > a[mid])
			return left;
		else
			return mid;
	}
	else //a[left] > a[rigth]
	{
		if (a[mid] > a[left])
			return left;
		else if (a[rigth] > a[mid])
			return rigth;
		else
			return mid;
	}
}
static int partion1(int* a, int left, int rigth)//hoare
{
	int mid = GetMid(a, left, rigth);
	swap(&a[left], &a[mid]);
	int key = left;
	while (left < rigth)
	{
		while (left<rigth && a[rigth] >= a[key])
		{
			rigth--;
		}
		while (left < rigth && a[left] <= a[key])
		{
			left++;
		}
		swap(&a[left], &a[rigth]);
	}
	swap(&a[left], &a[key]);
	return left;
}
static int partion2(int* a, int left, int rigth) //挖坑
{
	int mid = GetMid(a, left, rigth);
	swap(&a[left], &a[mid]);
	int provit = left;
	int key = left;
	while (left < rigth)
	{
		while (left < rigth && a[rigth] >= a[key])
		{
			rigth--;
		}
		a[rigth] = a[provit];
		provit = rigth;
		while (left < rigth && a[left] <= a[key])
		{
			left++;
		}
		a[left] = a[provit];
		provit = left;
	}
	a[left] = a[provit];
	return provit;
}

static int partion3(int* a, int left, int rigth) //前后指针
{
	int mid = GetMid(a, left, rigth);
	swap(&a[left], &a[mid]);
	int prev = left, cur = left + 1;
	int key = left;
	while (cur <= rigth)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[prev], &a[key]);
	return prev;
}
static void QuickSort(int* a, int left, int rigth)//快排
{
	if (left >= rigth)
		return;
	if (rigth - left + 1 <= 10)
	{
		InsertSort(a + left, rigth - left + 1);
	}
	else
	{
		//int key = partion1(a, left, rigth);
		//int key = partion2(a, left, rigth);
		int key = partion3(a, left, rigth);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, rigth);
	}
}
static void QuickSortNoR(int* a, int left, int rigth)//快排非递归
{
	ST st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, rigth);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		int key = partion1(a, begin, end);
		if (key + 1 < end)
		{
			StackPush(&st, key+1);
			StackPush(&st, end);
		}
		if (begin < key - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, key -1);
		}
	}
	StackDestroy(&st);
}
void _MrageSort(int* a, int left, int rigth, int* tmp)
{
	if (left >= rigth)
		return;
	int mid = left + ((rigth - left) >> 1);
	_MrageSort(a, left, mid, tmp);
	_MrageSort(a, mid + 1, rigth, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = rigth;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	for (int j = left; j <= rigth; j++)
	{
		a[j] = tmp[j];
	}
}
static void MrageSort(int* a, int n)//归并
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MrageSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
static void MrageSortNoR(int* a, int n)//归并非递归
{
	int gap = 1;
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}
			for (int j = i; j <= end2; j++)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
}
static void CountSort(int* a, int n)//计数
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
		if (max < a[i])
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	assert(count);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[i - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
}
static void SortPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InitArray(void (*p1)(int*, int), void (*p2)(int* a, int))
{
	int a[] = { 1,4,2,3,5,6,9,8,7,0 };
	int n = 10;
	p1(a, n);
	p2(a, 10);
}
void InsertTest(void (*p1)(int*, int),void (*p2)(int*a,int))  //回调
{
	InitArray(p1,p2);
}
void ShellTest(void (*p1)(int*, int), void (*p2)(int*a, int))   //回调
{
	InitArray(p1, p2);
}
void SeletcTest(void (*p1)(int*, int), void (*p2)(int* a, int))    //回调
{
	InitArray(p1, p2);
}
void HeapTest(void (*p1)(int*, int), void (*p2)(int* a, int))     //回调
{
	InitArray(p1, p2);
}
void MrageSortTest(void (*p1)(int*, int), void (*p2)(int* a, int)) //回调
{
	InitArray(p1, p2);
}
void MrageSortNoRTest(void (*p1)(int*, int), void (*p2)(int* a, int))//回调
{
	InitArray(p1, p2);
}
void Sort(void)//总接口
{
	int a[] = { 1,4,2,3,5,6,9,8,7,0 };
	void (*p[])(int*, int) = {InsertSort,ShellSort,SeletcSort,HeapSort,MrageSort,MrageSortNoR,SortPrint};
	//InsertSort(a, 10);
	//ShellSort(a, 10);
	//SeletcSort(a, 10);
	//HeapSort(a, 10);
	//BubbleSort(a, 10);
	//QuickSort(a, 0, 9);
	//MrageSort(a, 10);
	//MrageSortNoR(a, 10);
	//CountSort(a, 10);
	//QuickSortNoR(a, 0, 9);
	//p[1](a, 10);
	/*sort1(InsertSort,SortPrint);
	SortPrint(a, 10);*/
	InsertTest(p[0], p[6]); 
	ShellTest(p[1], p[6]);
	SeletcTest(p[2], p[6]);
	HeapTest(p[3], p[6]);
	MrageSortTest(p[4], p[6]);
	MrageSortNoRTest(p[5], p[6]);
}
