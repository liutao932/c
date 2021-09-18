#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_MAX 20
#define SEX_MAX 10
#define TEL_MAX 15
#define ADDR_MAX 30
#define PERSON_MAX 1000
struct PersonInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char telphone[TEL_MAX];
	char addr[ADDR_MAX];
};
struct Connect
{
	struct PersonInfo data[PERSON_MAX];
	int size;
};
void Init_Connect(struct Connect* pc);
void AddInfo(struct Connect *pc);
void ShowInfo(struct Connect* pc);
void FindInfo(struct Connect* pc);
void DelInfo(struct Connect* pc);
void SortInfo(struct Connect* pc);
