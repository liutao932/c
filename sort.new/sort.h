#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
extern void swap(int* a, int* b);//����
extern void InsertSort(int* a, int n);//��������
extern void ShellSort(int* a, int n);//ϣ������
extern void SeletcSort(int* a, int n);//ѡ������
extern void HeadSort(int* a, int n);//������
extern void AdjustDown(int* a, int parent, int n);//�ѵ����µ���
extern void BubbleSort(int* a, int n);//ð������
extern int partion1(int* a, int left, int rigth);//hoare
extern int partion2(int* a, int left, int rigth);//�ڿ�
extern int partion3(int* a, int left, int rigth);//ǰ��ָ��
extern void QuickSort(int* a, int left, int rigth);//��������
extern void QuickSortR(int* a, int left, int rigth);//���ŵķǵݹ�
extern void MergeSortR(int* a, int n);//�鲢�ķǵݹ�
extern void MergeSort(int* a, int n);//�鲢����
extern void CountSort(int* a, int n);//��������
extern void SortPrint(int* a, int n); //��ӡ
extern void SortTest(void);