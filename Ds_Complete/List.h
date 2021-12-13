#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>

typedef int ListNodeDataType;
typedef struct ListNode
{
	ListNodeDataType data;
	struct ListNode* next;
}LN;

extern LN*  NodeBuy(ListNodeDataType x); //申请节点
extern void NodePushBack(LN** head, ListNodeDataType x); //尾插
extern void NodePushFront(LN** head, ListNodeDataType x);//头插
extern void NodePopBack(LN** head);//尾删
extern void NodePopFront(LN** head);//头删
extern LN*  NodeFind(LN* head, ListNodeDataType x);//查找节点
extern void NodeInsert(LN* head,LN* Node, ListNodeDataType x);//在Node 节点之前插入
extern void NodeDestroy(LN** head);//销毁
extern void NodePrintf(LN* head);//打印
extern void NodeReverse(LN** head);//逆置
extern void NodeClassified(LN** head); //分类小于5在左边等于5的在中间大于5在右边，相对顺序不变
extern LN*  NodeMid(LN* head); //中间节点
extern bool NodePalindrome(LN* head); //判断是否回文
extern LN*  NodeTwoAdd(LN* l1, LN* l2);//两个链表相加
extern LN*  NodeTwoCross(LN* l1, LN* l2);//求相交节点
extern bool NodeCir(LN* head); //是否有环
extern LN*  NodeCirFirst(LN* head);//环的入口节点
extern LN*  NodeTwoSort(LN* l1, LN* l2); //两个有序链表的排序
extern LN*  NodeTwoReverse(LN* head, int left, int rigth); //逆置左节点和右节点区间
extern LN* NodeInsertSort(LN* head);//对链表进行插入排序
extern void ListNode();//总接口