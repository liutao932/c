#include"sort.h"
#include"stack.h"

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int  end = i;
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
		{
			max = min;
		}
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
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1); i >= 0; i--)
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
		if (exchange == 0)
		{
			break;
		}
		end--;
	}
}
int partion1(int* a, int left, int rigth)
{
	int keyi = left;
	while (left < rigth)
	{
		while (left < rigth && a[rigth] >= a[keyi])
			rigth--;
		while (left < rigth && a[left] <= a[keyi])
			left++;
		swap(&a[left], &a[rigth]);
	}
	swap(&a[left], &a[keyi]);
	return left;
}
int partion2(int* a, int left, int rigth)
{
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
	int prev = left, cur = left + 1;
	int keyi = left;
	while (cur <= rigth)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int left, int rigth)
{
	if (left >= rigth)
	{
		return;
	}
	if (rigth - left + 1 < 10)
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
void QuickSortNoR(int* a, int left, int rigth)
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
			StackPush(&st, key - 1);
		}
	}
	StackDestroy(&st);
}
void _MegreSort(int* a, int left, int rigth, int* tmp)
{
	if (left >= rigth)
		return;
	int mid = left + ((rigth - left) >> 1);
	_MegreSort(a, left, mid, tmp);
	_MegreSort(a, mid + 1, rigth, tmp);
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
void MegreSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
		return;
	_MegreSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
void MegreSortNoR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2* gap)
		{	
			int begin1 = i, end1 = i + gap-1;
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
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
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
	int range = max - min  + 1;
	int* count = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min] ++;
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
