#include"QuickNoR.h"
#include"sort.h"

void InsertTset()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	InsertSort(a, 10);
	PrintSort(a, 10);
}
void ShellTest()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	ShellSort(a, 10);
	PrintSort(a, 10);
}
void SeletcTest()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	SeletcSort(a, 10);
	PrintSort(a, 10);
}
void HeapTest()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	HeapSort(a, 10);
	PrintSort(a, 10);
}
void BubbleTest()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	BubbleSort(a, 10);
	PrintSort(a, 10);
}
void QuickTest()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	//QuickSort(a, 0, 9);
	QuickNoR(a, 0, 9);
}
void MergeTest()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	//MergeSort(a, 10);
	MergrSortNon(a, 10);
	PrintSort(a, 10);
}
void ConutTest()
{
	int a[] = { 1,6,2,3,4,9,0,8,7,5 };
	CountSort(a, 10);
	PrintSort(a, 10);
}
int main()
{
	InsertTset();
	ShellTest();
	SeletcTest();
	HeapTest();
	BubbleTest();
	QuickTest();
	MergeTest();
	ConutTest();
}