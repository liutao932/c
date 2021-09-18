#include"connect.h"
void Init_Connect(struct Connect* pc)
{
	memset(pc->data, 0, sizeof(pc->data));
	pc->size = 0;
}

void AddInfo(struct Connect* pc)
{
	int input = 0;
	if (pc->size == PERSON_MAX)
	{
		printf("connect is full ");
	}
	printf("what do you need to add person'numbers ?\n");
	scanf("%d", &input);
	for (int i = 0; i < input; i++)
	{
		printf("please input %d person's name:>", i +1);
		scanf("%s", pc->data[pc->size].name);
		printf("\nplease input %d person's age:>", i +1);
		scanf("%d", &pc->data[pc->size].age);
		printf("\nplease input %d person's sex:>", i +1);
		scanf("%s", pc->data[pc->size].sex);
		printf("\nplease input %d person's telphone:>", i +1);
		scanf("%s", pc->data[pc->size].telphone);
		printf("\nplease input %d person's addr:>", i +1);
		scanf("%s", pc->data[pc->size].addr);
		printf("add %d PersonInfomation is sucess\n", i + 1);
		pc->size++;
	}
}
void ShowInfo(struct Connect* pc)
{
	for (int i = 0; i < pc->size; i++)
	{
		printf("name:%s", pc->data[i].name);
		printf("\tage:%d", pc->data[i].age);
		printf("\tsex:%s", pc->data[i].sex);
		printf("\ttelphone:%s", pc->data[i].telphone);
		printf("\taddr:%s\n", pc->data[i].addr);
	}
}
void FindInfo(struct Connect* pc)
{
	printf("please you need to search's person name\n");
	char name[20];
	scanf("%s", name);
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			printf("find the person\n");
			printf("name:%s", pc->data[i].name);
			printf("\tage:%d", pc->data[i].age);
			printf("\tsex:%s", pc->data[i].sex);
			printf("\ttelphone:%s", pc->data[i].telphone);
			printf("\taddr:%s\n", pc->data[i].addr);
			return;
		}
	}
	printf("no find the person information");
}
void DelInfo(struct Connect* pc)
{
	printf("please input you need to del's name:>");
	char name[20];
	scanf("%s", name);
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			pc->data[i] = pc->data[i + 1];
			pc->size--;
		}
	}
	printf("del is sucess\n");
}
void menu1()
{
	printf("------1:From big to small---\n");
	printf("------2:From small to big---\n");
}
void SortInfo(struct Connect* pc)
{
	menu1();
	int choice;
	printf("please input your choice:>");
	scanf("%d", &choice);
	if (choice == 1)
	{
		for (int i = 0; i < pc->size; i++)
		{
			for (int j = i + 1; j < pc->size; j++)
			{
				if (pc->data[j].age < pc->data[i].age)
				{
					struct PersonInfo tmp = pc->data[j];
					pc->data[j] =pc->data[i];
					pc->data[i] = tmp;
				}
			}
		}
	}
	else if (choice == 2)
	{
		for (int i = 0; i < pc->size; i++)
		{
			for (int j = i + 1; j < pc->size; j++)
			{
				if (pc->data[j].age > pc->data[i].age)
				{
					struct PersonInfo tmp = pc->data[j];
					pc->data[j] = pc->data[i];
					pc->data[i] = tmp;
				}
			}
		}
	}
}