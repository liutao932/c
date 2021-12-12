#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
extern void swap(int* a, int* b);//交换
extern void InsertSort(int* a, int n);//插入排序
extern void ShellSort(int* a, int n);//希尔排序
extern void SeletcSort(int* a, int n);//选择排序
extern void HeadSort(int* a, int n);//堆排序
extern void AdjustDown(int* a, int parent, int n);//堆的向下调整
extern void BubbleSort(int* a, int n);//冒泡排序
extern int partion1(int* a, int left, int rigth);//hoare
extern int partion2(int* a, int left, int rigth);//挖坑
extern int partion3(int* a, int left, int rigth);//前后指针
extern void QuickSort(int* a, int left, int rigth);//快速排序
extern void QuickSortR(int* a, int left, int rigth);//快排的非递归
extern void MergeSortR(int* a, int n);//归并的非递归
extern void MergeSort(int* a, int n);//归并排序
extern void CountSort(int* a, int n);//计数排序
extern void SortPrint(int* a, int n); //打印
extern void SortTest(void);