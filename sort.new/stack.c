#include"stack.h"
void StackInit(ST* pc) //��ʼ��ջ
{
	assert(pc);
	pc->a = NULL;
	pc->size = pc->capatity = 0;
}
void StackPush(ST* pc, StackDataType x)//ѹջ
{
	assert(pc);
	if (pc->size == pc->capatity)
	{
		int newcapatity = pc->capatity == 0 ? 4 : pc->capatity * 2;
		StackDataType* tmp = (StackDataType*)realloc(pc->a,sizeof(StackDataType) * newcapatity);
		if (tmp == NULL)
			return;
		pc->a = tmp;
		pc->capatity = newcapatity;
	}
	pc->a[pc->size++] = x;
}
StackDataType StackTop(ST* pc)//ȡջ��Ԫ��
{
	assert(pc);
	assert(!StackEmpty(pc));
	return pc->a[pc->size - 1];
}
void StackPop(ST* pc)//��ջ
{
	assert(pc);
	assert(!StackEmpty(pc));
	pc->size--;
}
bool StackEmpty(ST* pc)//�ж�ջ�Ƿ�Ϊ��
{
	assert(pc);
	return pc->size == 0;
}
void StackDestroy(ST* pc)//����ջ
{
	assert(pc);
	free(pc->a);
	pc->size = pc->capatity = 0;
}