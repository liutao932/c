#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void swap(int* a, int* b);//交换
void InsertSort(int* a, int n);//插入排序
void ShellSort(int* a, int n); //希尔排序
void SeletcSort(int* a, int n);//选择排序
void AdjustDown(int* a, int parent, int n);//堆的向下调整
void AdjustUp(int* a, int child);//堆的向上调整
void HeapSort(int* a, int n);//堆排序
void BubbleSort(int* a, int n);//冒泡排序
int  GetMid(int* a, int left, int right); //三数去中
void QuickSort(int* a, int left, int rigth); //快速排序
void MergeSort(int* a, int n);//归并排序
void MergrSortNon(int* a, int n); //归并的非递归
void CountSort(int* a, int n); //计数排序
int  partion1(int* a, int left, int rigth);//hoare法
int  partion2(int* a, int left, int rigth);//挖坑法
int  partion3(int* a, int left, int rigth);//前后指针法
void PrintSort(int* a, int n);//打印