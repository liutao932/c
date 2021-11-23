#include"sort.h"

void PrintSort(int* a, int n)//打印
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void swap(int* a, int* b)//交换
{
	int tmp = *a;
	*a = *b; 
	*b = tmp;
}
void InsertSort(int* a, int n)//插入排序
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
void ShellSort(int* a, int n) //希尔排序
{
	assert(a);
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
void SeletcSort(int* a, int n)//选择排序
{
	int begin = 0, end = n - 1;
	while (begin <= end)
	{
		int min = begin, max = end;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		swap(&a[begin], &a[min]);
		if (max == begin)
		{
			max = min;
		}
		swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}
void AdjustUp(int* a, int child)//堆的向上调整
{
	assert(a);
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
void AdjustDown(int* a, int parent, int n)//堆的向下调整
{
	assert(a);
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
void HeapSort(int* a, int n)//堆排序
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
void BubbleSort(int* a, int n)//冒泡排序
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
			break;
	}
}
int GetMid(int* a, int left, int right) //三数去中
{
	int mid = left + ((right - left) >> 1);
	if (a[left] > a[right])
	{
		if (a[mid] > a[left])
			return left;
		else if (a[right] > a[mid])
			return right;
		else
			return mid;
	}
	else  //a[left] <= a[rigth]
	{
		if (a[mid] < a[left])
			return mid;
		else if (a[mid] > a[right])
			return right;
		else
			return mid;
			
	}
}
int partion1(int* a, int left, int rigth)//hoare法
{
	int mid = GetMid(a, left, rigth);
	swap(&a[left], &a[mid]);
	int keyi = left;
	while (left < rigth)
	{
		while (left < rigth && a[rigth] >= a[keyi])  //找小
		{
			rigth--;
		}
		while (left < rigth && a[left] <= a[keyi]) //找大
		{
			left++;
		}
		swap(&a[left], &a[rigth]);    //小的往左边甩，大的往右边甩
	}
	swap(&a[left], &a[keyi]);
	return left;
}
int  partion2(int* a, int left, int rigth)//挖坑法
{
	int mid = GetMid(a, left, rigth);
	swap(&a[left], &a[mid]);
	int provit = left;
	int key = a[left];
	while (left < rigth)
	{
		while (left < rigth && a[rigth] >= key)
		{
			rigth--;
		}
		a[provit] = a[rigth];  //让坑位在右边
		provit = rigth;
		while (left < rigth && a[left] <= key)
		{
			left++;
		}
		a[provit] = a[left];
		provit = left;          //把坑位放在左边
	}
	a[provit] = key;
	return provit;
}
int partion3(int* a, int left, int rigth)//前后指针法
{
	int mid = GetMid(a, left, rigth);
	swap(&a[left], &a[mid]);
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= rigth)
	{
		if (a[cur] >= a[key] && ++prev != cur)
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	swap(&a[prev], &a[key]);
	return prev;
}
void QuickSort(int* a, int left, int rigth) //快速排序
{
	if (left >= rigth)
		return;
	if (rigth - left + 1 < 10)
	{
		InsertSort(a + left, rigth - left + 1); //在个数小于10的时，可以采取插入来
	                                         	//优化递归次数
	}
	else
	{
		int key = partion1(a, left, rigth);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, rigth);
	}
	
}
void _MergeSort(int* a, int left, int rigth, int* tmp)
{
	if (left >= rigth)
		return;
	int mid = left + ((rigth - left) >> 1);
	_MergeSort(a, left, mid, tmp);      //递归左区间
	_MergeSort(a, mid + 1, rigth, tmp);   //递归右区间

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = rigth;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (int j = left; j <= rigth; j++)
	{
		a[j] = tmp[j];
	}
}
void MergeSort(int* a, int n)//归并排序
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
void MergrSortNon(int* a, int n) //归并的非递归
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
		return;
	int  gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap -1]   [i+gap] [i+2*gap -1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
			if (end1 >= n || begin1 >= n)
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
	for (int i = 0; i < range; i++)
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