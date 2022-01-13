#include"sort.h"

//
//
//
//extern void InsertSort(int* a, int n);
//extern void ShellSort(int* a, int n);
//extern void SeletcSort(int* a, int n);
//extern void HeapSort(int* a, int n);
//extern void BubbleSort(int* a, int n);
//extern void QuickSort(int* a, int left, int rigth);
//extern void QuickSortNoR(int* a, int left, int rigth);
//extern void MegreSort(int* a, int n);
//extern void MegreSortNoR(int* a, int n);
//extern void CountSort(int* a, int n);
void test(void)
{
	int array[] = { 1,2,3,4,5,6,9,8,7,0 };
	//InsertSort(array, 10);
	//ShellSort(array, 10);
	//SeletcSort(array, 10);
	//HeapSort(array, 10);
	//BubbleSort(array, 10);
	//QuickSort(array, 0, 9);
	//MegreSort(array, 10);
	//MegreSortNoR(array, 10);
	//CountSort(array, 10);
	QuickSortNoR(array, 0, 9);
	for(int i = 0; i< 10; i++)
	{
		printf("%d ", *(array + i));
	}
}
int main()
{
	test();
}