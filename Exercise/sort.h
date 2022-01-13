#pragma once
#define _SORT_H_
#ifdef _SORT_H_
#include<stdio.h>
#include<stdlib.h>

extern void InsertSort(int* a, int n);
extern void ShellSort(int* a, int n);
extern void SeletcSort(int* a, int n);
extern void HeapSort(int* a, int n);
extern void BubbleSort(int* a, int n);
extern void QuickSort(int* a, int left, int rigth);
extern void QuickSortNoR(int* a, int left, int rigth);
extern void MegreSort(int* a, int n);
extern void MegreSortNoR(int* a, int n);
extern void CountSort(int* a, int n);
#endif // _SORT_H_
