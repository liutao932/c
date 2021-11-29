#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

void SortPrint(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void SeletcSort(int* a, int n);
void HeapSort(int* a, int n);
void BubbleSort(int* a, int n);

int partion1(int* a, int left, int rigth);
int partion2(int* a, int left, int rigth);
int partion3(int* a, int left, int rigth);
void QuickSortR(int* a, int left, int rigth);
void QuickSortNoR(int* a, int left, int rigth);
void MergeSortR(int* a, int n);
void MergeSortNoR(int* a, int n);
void CountSort(int* a, int n);

void swap(int* a, int* b);
void AdjustDown(int* a, int parent, int n);