#include"sort.h"
#include"stack.h"

static void swap(int* a, int* b)//交换
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
static void InsertSort(int* a, int n)//插入排序
{
	assert(a);
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
static void ShellSort(int* a, int n)//希尔排序
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
static void SeletcSort(int* a, int n)//选择排序
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
static void AdjustDown(int* a, int parent, int n)//堆的向下调整
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
static void HeadSort(int* a, int n)//堆排序
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
static void BubbleSort(int* a, int n)//冒泡排序
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
static int partion1(int* a, int left, int rigth)//hoare
{
	int keyi = left;
	while (left <rigth)
	{
		while (left <rigth && a[rigth] >= a[keyi])
			rigth--;
		while (left < rigth && a[left] <= a[keyi])
			left++;
		swap(&a[left], &a[rigth]);
	}
	swap(&a[left], &a[keyi]);
	return left;
}
static int partion2(int* a, int left, int rigth)//挖坑
{
	int provit = left;
	int key = a[left];
	while (left < rigth)
	{
		while (left < rigth && a[rigth] >= key)
		{
			rigth--;
		}
		a[provit] = a[rigth];
		provit = rigth;
		while (left < rigth && a[left] <= key)
		{
			left++;
		}
		a[provit] = a[left] ;
		provit = left;
	}
	a[provit] = key;
	return provit;			
}
static int partion3(int* a, int left, int rigth)//前后指针
{
	int prev = left, cur = left + 1;
	int key = left;
	while (cur <= rigth)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	swap(&a[prev], &a[key]);
	return prev;
}
static void QuickSort(int* a, int left, int rigth)//快速排序
{
	if (rigth - left + 1 <= 10)
	{
		InsertSort(a + left, rigth - left + 1);
	}
	else
	{
		if (left >= rigth)
			return;
		//int key = partion1(a, left, rigth);
		//int key = partion2(a, left, rigth);
		int key = partion3(a, left, rigth);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, rigth);
	}
}
static void QuickSortR(int* a, int left, int rigth)//快排的非递归
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
			StackPush(&st, key + 1);
			StackPush(&st, end);
		}
		if (begin < key - 1)
		{
			StackPush(&st, begin);
			StackPush(&st,key-1) ;
		}
	}
	StackDestroy(&st);
}
static void MergeSortR(int* a,int n)//归并的非递归
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = begin1;
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
static void _MergeSort(int* a, int left, int rigth,int *tmp)
{
	if (left >= rigth)
		return;
	int mid = left + ((rigth - left) >> 1);
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, rigth, tmp);
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
	for (int i = left; i <= rigth; i++)
	{
		a[i] = tmp[i];
	}
}
static void MergeSort(int* a, int n)//归并排序
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
static void CountSort(int* a, int n)//计数排序
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
		count[i-min]++;
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
static void SortPrint(int* a, int n) //打印
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void SortTest()
{
	int array[] = { 9,7,6,8,5,3,2,1,0,4 };
	//InsertSort(array,10);
	//ShellSort(array, 10);
	//SeletcSort(array, 10);
	//HeadSort(array, 10);
	//BubbleSort(array, 10);
	//QuickSort(array, 0,9);
	//MergeSort(array, 10);
	//MergeSortR(array, 10);
	//QuickSortR(array, 0, 9);
	CountSort(array, 10);
	SortPrint(array, 10);
}