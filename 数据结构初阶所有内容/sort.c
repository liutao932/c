#include"sort.h"
#include"stack.h"
#include<string.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SortPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
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
void ShellSort(int* a, int n)
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
void SeletcSort(int* a, int n)
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
			max = min;
		swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}
void AdjustDown(int* a, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
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
void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
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
void HeapSort(int* a, int n)
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
void BubbleSort(int* a, int n)
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
	if (a[left] > a[rigth])
	{
		if (a[mid] > a[left])
			return left;
		else if (a[rigth] > a[mid])
			return rigth;
		else
			return mid;
	}
	else
	{
		if (a[mid] < a[rigth])
			return rigth;
		else if (a[left] > a[mid])
			return left;
		else
			return mid;
	}
}
int  partion1(int* a, int left, int rigth)
{
	int mid = GetMid(a, left, rigth);
	swap(&a[mid], &a[left]);
	int key = left;
	while (left < rigth)
	{
		while (left < rigth && a[rigth] >= a[key])
			rigth--;
		while (left < rigth && a[left] <= a[key])
			left++;
		swap(&a[left], &a[rigth]);
	}
	swap(&a[left], &a[key]);
	return left;
}
int partion2(int* a, int left, int rigth)
{
	int mid = GetMid(a, left, rigth);
	swap(&a[mid], &a[left]);
	int provit = left;
	int key = a[left];
	while (left < rigth)
	{
		while (left < rigth && a[rigth] >= key)
			rigth--;

		a[provit] = a[rigth];
		provit = rigth;
		while (left < rigth && a[left] <= key)
			left++;

		a[provit] = a[left];
		provit = left;
	}
	a[provit] = key;
	return provit;
}
int partion3(int* a, int left, int rigth)
{
	int mid = GetMid(a, left, rigth);
	swap(&a[mid], &a[left]);
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
void QuickSortR(int* a, int left, int rigth)
{
	if (left >= rigth)
		return;
	if (rigth - left + 1 < 10)
	{
		InsertSort(a + left, rigth - left + 1);
	}
	else
	{
		//int key = partion1(a, left, rigth);
		int key = partion2(a, left, rigth);
		//int key = partion3(a, left, rigth);
		QuickSortR(a, left, key - 1);
		QuickSortR(a, key + 1, rigth);
	}
	
}
void QuickSortNoR(int* a, int left, int rigth)
{
	S s;
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
			StackPush(&s, key +1);
			StackPush(&s, end);
		}
		if (begin < key - 1)
		{
			StackPush(&s,begin);
			StackPush(&s, key -1);
		}
	}
	StackDestroy(&s);
}
void _MergeSortR(int* a, int left, int rigth, int* tmp)
{
	if (left >= rigth)
		return;
	int mid = left + ((rigth - left) >> 1);
	_MergeSortR(a, left, mid, tmp);
	_MergeSortR(a, mid + 1, rigth, tmp);
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
void MergeSortR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSortR(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
void MergeSortNoR(int* a, int n)
{
	int gap = 1;
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	memset(tmp, 0, sizeof(int) * n);
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
	free(tmp);
}
//void CountSort(int* a, int n)
//{
//	int min = a[0], max = a[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i] < min)
//		{
//			min = a[i];
//		}
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//	}
//	int range = max - min + 1;
//	int* count = (int*)malloc(sizeof(int) * range);
//	assert(count);
//	memset(count, 0, sizeof(int) * range);
//	for (int i = 0; i < n; i++)
//	{
//		count[a[i] - min]++;
//	}
//	int j = 0;
//	for (int i = 0; i < range; i++)
//	{
//		while (count[i]--)
//		{
//			a[j++] = i + min;
//		} 
//	}
//}
void CountSort(int* a, int n) //计数排序
{
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
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
	if (count == NULL)
		return;
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
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