#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)
#define STR(s) #s
void Reverse(char* str)
{
	size_t rigth = strlen(str) - 1;
	size_t left = 0;
	while (left < rigth)
	{
		char tmp = str[left];
		str[left++] = str[rigth];
		str[rigth--] = tmp;
	}
}
char* ExchangeStr(int num)
{
	char* str = (char*)calloc(10, sizeof(char));    //calloc（空间大小，数据类型的大小）
	assert(str);
	int i = 0;
	while (num)
	{
		int tmp = num % 10;
		str[i++] = tmp + '0';
		num /= 10;
	}
	Reverse(str);
	return str;
}
int main()
{
	int x = 1234;
	//step 1:用函数实现
	printf(ExchangeStr(x));
	//step 2: 用标准库函数
#ifdef DEBUG

	char buf[64] = { 0 };
	printf("\n");
	printf(itoa(x, buf, 10));
#endif // DEBUG
	printf("\n");
	//step 3: 用 # 定义宏的方法
	char buf[64] = { 0 };
	strcpy(buf, STR(1234));
	printf(buf);
	return 0;
}
