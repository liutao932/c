#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void func(char para[100])
//{
//	void* p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//#include<string.h>
//int main()
//{
//	/*char a = 101;
//	int sum = 200;
//	a += 27;
//	sum += a;
//	printf("%d", sum);*/
//	/*int value = 1024;
//	char condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	printf("%d %d", value, condition);*/
//	char para[100] = { 0 };
//	func(para);
//}
//#include <stdio.h>
//void func(char* p) { p = p + 1; }
//int main()
//{
//	char s[] = { '1', '2', '3', '4' };
//	func(s);
//	printf("%c", *s);
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//int ReverseNumber(int  EndNumber)
//{
//   int ret = 0;
//    int count = EndNumber, pos = 0;
//    while (count)
//    {
//        pos++;
//        count /= 10;
//    }
//    int* array = (int*)malloc(sizeof(int) * pos);
//    assert(array);
//    int i = 0;
//    while (EndNumber)
//    {
//        array[i++] = EndNumber % 10;
//        EndNumber /= 10;
//    }
//    int left = 0, rigth = i - 1;
//    while (left < rigth)
//    {
//        int tmp = array[left];
//        array[left++] = array[rigth];
//        array[rigth--] = tmp;
//    }
//    for (int j = 0; j < i; j++)
//    {
//        ret = ret * 10 + array[j];
//    }
//    return ret;
//}
//int CountNumber(int number)
//{
//    int  res = 0;
//   
//    for (int i = 0; i <= number; i++)
//    {
//        int pos = 0;
//        int count = i;
//        while (count)
//        {
//            pos++;
//            count /= 10;
//        }
//        int SunNumber = i * i;
//        int EndNumber = 0;
//        while (pos)
//        {
//            int tmp = SunNumber % 10;
//            EndNumber = EndNumber * 10 + tmp;
//            SunNumber /= 10;
//            pos--;
//        }
//        EndNumber = ReverseNumber(EndNumber);
//        if (i == EndNumber)
//        {
//            res++;
//        }
//    }
//    return res;
//}
//int main()
//{
//    int number;
//    int ret = 0;
//    while (scanf("%d", &number) != EOF)
//    {
//        ret = CountNumber(number);
//        printf("%d\n", ret);
//    }
//}


//void fun(char** p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//} 
//int main()
//{
//	char* s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
//	fun(s);
//	printf("\n");
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	static char* s[] = { "black", "white", "pink", "violet" };
//	char** ptr[] = { s + 3, s + 2, s + 1, s }, *** p;
//	p = ptr;
//	++p;
//	printf("%s", **p + 1);
//	return 0;
//} 


//int main()
//{
//	char* str = "000000000";
//	printf(str);
//}strc
//
//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n -1; i++)
//	{
//		int end = i;
//		int x = a[end + 1];
//		while (end >= 0)
//		{
//			if (a[end] > x)
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = x;
//	}
//}
//int main(){
//
//	int array[] = { 1,2,4,5,7,2,9,0 };
//	InsertSort(array, 8);
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", *(array+ i));
//	}
//}
//#include"sort.h"
//int main()
//{
//	int array[] = { 9,7,6,4,8,3,5,2,0,1 };
//	//InsertSort(array, 10);
//	//ShellSort(array, 10);
//	//SeletcSort(array, 10);
//	//HeapSort(array, 10);
//	//BubbleSort(array, 10);
//	QuickSort(array, 0,9);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(array + i));
//	}
//}



	//	int main() {
	//	int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//	int(*p)[4] = (int(*)[4])m;
	//	printf("%d", p[1][2]);
	//	return 0;
	//}

//int main()
//{
//	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;
//}


//char* f(char* str, char ch)
//{
//	char* it1 = str;
//	char* it2 = str;
//	while (*it2 != '\0')
//	{
//		while (*it2 == ch)
//		{
//			it2++;
//		} *
//			it1++ = *it2++;
//	} 
//		r	eturn str;
//}
//int main() {
//	char a[10];
//	strcpy(a, "abcdcccd");
//	printf("%s", f(a, 'c'));
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    char str[100];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%s", str);
//        int len = strlen(str);
//        if (len <= 10)
//        {
//            printf(str);
//        }
//        else
//        {
//            if (len <= 12)
//            {
//                int pos = 0;
//                str[pos++] = str[0];
//                str[pos++] = len + '0';
//                str[pos++] = str[len - 1];
//                str[pos++] = '\0';
//                printf(str);
//            }
//            else
//            {
//                int pos = 3;
//                str[pos--] = str[len - 1];
//                while (len)
//                {
//                    str[pos--] = len % 10 + '0';
//                    len /= 10;
//                }
//                str[pos--] = str[0];
//                str[4] = '\0';
//                printf(str);
//            }
//        }
//    }
//}
//

//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    char str[100];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%s", str);
//        int len = strlen(str);
//        if (len < 10)
//        {
//            printf("%s\n",str);
//        }
//        else
//        {
//            if (len < 12)
//            {
//                int count = len - 2;
//                int pos = 0;
//                str[pos++] = str[0];
//                str[pos++] = count + '0';
//                str[pos++] = str[len - 1];
//                str[pos++] = '\0';
//                printf("%s\n", str);
//            }
//            else
//            {
//                int count = len - 2;
//                int pos = 3;
//                str[pos--] = str[len - 1];
//                while (count)
//                {
//                    str[pos--] = count % 10 + '0';
//                    count /= 10;
//                }
//                str[pos--] = str[0];
//                str[4] = '\0';
//                printf("%s\n", str);
//            }
//        }
//    }
//}



//int main()
//{
//	char arr[2][4]= {"you&","me"};
//	/*strcpy(arr[0], "you");
//	strcpy(arr[1], "me");
//	arr[0][3] = '&';*/
//	printf("%s \n", arr);
//	return 0;
//}
//struct st
//{
//	int* p;
//	int i;
//	char a;
//};
//int main()
//{
//	int sz = sizeof(struct st);
//	printf("%d", sz);
//}

//void reverse(char* s)
//{
//    int left = 0, rigth = strlen(s) - 1;
//    while (left < rigth)
//    {
//        char tmp = s[left];
//        s[left++] = s[rigth];
//        s[rigth--] = tmp;
//    }
//}
//char* myItoa(char* tmp, int count)
//{
//    int index = 0;
//    while (count)
//    {
//        tmp[index++] = count % 10 + '0';
//        count /= 10;
//    }
//    tmp[index++] = '\0';
//    reverse(tmp);
//    return tmp;
//}
//char* compressString(char* S) {
//    int len = strlen(S);
//    char* str = (char*)malloc(sizeof(char) * len);
//    char* tmp = (char*)malloc(sizeof(char) * len);
//    int pos = 0, count = 0;
//    char* prev = S, * cur = S;
//    while (*cur != '\0')
//    {
//        if (*cur == *prev)
//        {
//            count++;
//            cur++;
//        }
//        else
//        {
//            str[pos++] = *prev;
//            tmp = myItoa(str, count);
//            int i = 0;
//            while (count)
//            {
//                i++;
//                count /= 10;
//            }
//            for (int j = 0; i < i; i++)
//            {
//                str[pos++] = tmp[j];
//            }
//            prev = cur;
//            count = 0;
//        }
//    }
//    return str;
//}
//char* compressString(char* S) {
//    int len = strlen(S);
//    char* str = (char*)malloc(sizeof(char) * len);
//    int prev = 0, cur = 1;
//    int count = 1, pos = 0;
//    while (cur < len)
//    {
//        if (S[prev] == S[cur])
//        {
//            prev++;
//            cur++;
//            count++;
//        }
//        else
//        {
//            str[pos++] = S[prev];
//            str[pos++] = count + '0';
//            prev++;
//            cur++;
//            count = 1;
//        }
//    }
//    if (S[prev] != S[cur - 1])
//    {
//        str[pos++] = S[cur - 1];
//        str[pos++] = '1';
//    }
//    else
//    {
//        str[pos++] = S[cur - 1];
//        str[pos++] = count + '0';
//    }
//    str[pos++] = '\0';
//    return str;
//}
//int main()
//{
//    char str[] = "aabccccccccccccccccccccccccccccaaa";
//    printf("%s", compressString(str));
//}
//void reverse(char* str)
//{
//	int left = 0, rigth = strlen(str) - 1;
//	while (left < rigth)
//	{
//		char tmp = str[left];
//		str[left++] = str[rigth];
//		str[rigth--] = tmp;
//	}
//}
//char* str(int num)
//{
//	int count = 0;
//	int num1 = num;
//	while (num1)
//	{
//		count++;
//		num1 /= 10;
//	}
//	char* array = (char*)malloc(sizeof(char) * count);
//	int pos = 0;
//	while (num)
//	{
//		array[pos++] = num % 10 + '0';
//		num /= 10;
//	}
//	array[pos++] = '\0';
//	reverse(array);
//	return array;
//}
//int main()
//{
//	char* p = NULL;
//	int num = 100;
//	p = str(num);
//	printf("%d\n", strlen(p));
//	printf(p);
//}
//void reverse(char* str)
//{
//    int left = 0, rigth = strlen(str) - 1;
//    while (left < rigth)
//    {
//        char tmp = str[left];
//        str[left++] = str[rigth];
//        str[rigth--] = tmp;
//    }
//}
//char* strnum(int num)
//{
//    int count = 0;
//    int num1 = num;
//    while (num1)
//    {
//        count++;
//        num1 /= 10;
//    }
//    char* array = (char*)malloc(sizeof(char) * count);
//    int pos = 0;
//    while (num)
//    {
//        array[pos++] = num % 10 + '0';
//        num /= 10;
//    }
//    array[pos++] = '\0';
//    reverse(array);
//    return array;
//}
//char* compressString(char* S) {
//    int len = strlen(S);
//    char* str = (char*)malloc(sizeof(char) * 50000);
//    char* p = NULL;
//    char* CountStr = NULL;
//    int prev = 0, cur = 1;
//    int count = 1, pos = 0;
//    while (cur < len)
//    {
//        if (S[prev] == S[cur])
//        {
//            prev++;
//            cur++;
//            count++;
//        }
//        else
//        {
//            str[pos++] = S[prev];
//            p = strnum(count);
//            for (int i = 0; i < strlen(p); i++)
//            {
//                str[pos++] = p[i];
//            }
//            // str[pos++] = count + '0';
//            prev++;
//            cur++;
//            count = 1;
//        }
//    }
//    if (S[prev] != S[cur - 1])
//    {
//        str[pos++] = S[cur - 1];
//        str[pos++] = '1';
//    }
//    else
//    {
//        str[pos++] = S[cur - 1];
//        p = strnum(count);
//        for (int i = 0; i < strlen(p); i++)
//        {
//            str[pos++] = p[i];
//        }
//        // str[pos++] = count + '0';
//    }
//    str[pos++] = '\0';
//    if (pos > len)
//    {
//        return S;
//    }
//    return str;
//}
//int main()
//{
//    char str[] = "aabcccccaa";
//    printf("%s", compressString(str));
//}
//#include <stdio.h>
//typedef struct List_t
//{
//	struct List_t* next;
//	struct List_t* prev;
//	char data[0];
//}list_t;
//int main()
//{
//	printf("%d", sizeof(list_t));
//	return 0;
//}
//#include<stdio.h>
//void fut(int** s, int p[2][3])
//{
//	**s = p[1][1];
//} 
//int main()
//{
//	int a[2][3] = { 1,3,5,7,9,11 }, * p;
//	p = (int*)malloc(sizeof(int));
//	fut(&p, a);
//	printf("%d", *p);
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//bool JusuDent(int number)
//{
//    while (number)
//    {
//        int tmp = number % 10;
//        if (tmp == 7)
//        {
//            return true;
//        }
//        number /= 10;
//    }
//    return false;
//}
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        int count = 0;
//        for (int i = 1; i <= n; i++)
//        {
//            if (i % 7 == 0)
//            {
//                count++;
//            }
//            if (JusuDent(i))
//            {
//                count++;
//            }
//        }
//        printf("%d\n", count);
//    }
//}

//#include<stdio.h>
//void fun(char* fname, char* st)
//{
//	FILE* myf;
//	int i;
//	myf = fopen(fname, "w");
//	for (i = 0; i < strlen(st); i++) fputc(st[i], myf);
//	fclose(myf);
//} 
//int main()
//{
//	fun("test.txt", "new world");
//	fun("test.txt", "hello,");
//	return 0;
//}
//#include<stdio.h>
//#define Mul(x,y) ++x*++y
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	//printf("%d", Mul(a + b, b + c));
//	printf("%d", ++a + b * ++b + c);
//	return 0;
//}


//#include <stdio.h>
//#define a 10
//void foo();
//int main()
//{
//	printf("%d..", a);
//	foo();
//	printf("%d", a);
//	return 0;
//} 
//void foo() {
//#undef a
//#define a 50
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
bool JustKon(char ch)
{
    if (ch == ' ')
    {
        return true;
    }
    return false;
}
int main()
{
    char str[1000];
    scanf("%s", str);
    char* p = str;
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;;
    while (*p != '\0')
    {
        if (isalpha(*p))
        {
            x1++;
        }
        if (JustKon(*p))
        {
            x2++;
        }
        if (isdigit(*p))
        {
            x3++;
        }
        else
        {
            x4++;
        }
        p++;
    }
    printf("%d\n", x1);
    printf("%d\n", x2);
    printf("%d\n", x3);
    printf("%d\n", x4);
}
