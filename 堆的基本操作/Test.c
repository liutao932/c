#include"Heap.h"


void test()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 10,100,90,74,20,86,57 };
	for (int i = 0; i < 7; i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);
}
int main()
{
	test();
}