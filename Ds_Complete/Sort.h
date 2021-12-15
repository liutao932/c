#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
extern void swap(int* a, int* b);
extern void InsertSort(int* a, int n);//插入
extern void ShellSort(int* a, int n);//希尔
extern void SeletcSort(int* a, int n);//选择
extern void AdjustDown(int* a, int parent, int n);//向下
extern void AdjustUp(int* a, int child);//向上
extern void HeapSort(int* a, int n);//堆排
extern void BubbleSort(int* a, int n);//冒泡
extern int partion1(int* a, int left, int rigth);//hoare
extern int partion2(int* a, int left, int rigth); //挖坑
extern int partion3(int* a, int left, int rigth); //前后指针
extern void QuickSort(int* a, int left, int rigth);//快排
extern void QuickSortNoR(int* a, int left, int rigth);//快排非递归
extern void MrageSort(int* a, int n);//归并
extern void MrageSortNoR(int* a, int n);//归并非递归
extern void CountSort(int* a, int n);//计数
extern void SortPrint(int* a, int n);
extern void Sort(void);//总接口

