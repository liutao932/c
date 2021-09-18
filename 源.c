#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"connect.h"
void menu()
{
	printf("-------------1.AddPerson------\n");
	printf("-------------2.ShowPersonInfo-\n");
	printf("-------------3.FindPersonInfo-\n");
	printf("-------------4.DelPersonInfo--\n");
	printf("-------------5.SortPersonInfo-\n");
	printf("-------------0.exit-----------\n");
}
enum MyEnum
{
	EXIT,
	ADD,
	SHOW,
	FIND,
	DEL,
	SORT
};
int main()
{
	int input = 0;
	struct Connect  c;
    Init_Connect(&c);
	do
	{
		menu();
		printf("please your inpit\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddInfo(&c);
			break;
		case SHOW:
			ShowInfo(&c);
			break;
		case FIND:
			FindInfo(&c);
			break;
		case DEL:
			DelInfo(&c);
			break;
		case SORT:
			SortInfo(&c);
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (input);
}
