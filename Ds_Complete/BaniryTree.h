#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include"Queue.h"

typedef char BaniryTreeData;
typedef struct BaniryTreeNode
{
	BaniryTreeData data;
	struct BaniryTreeNode* left;
	struct BaniryTreeNode* rigth;
}BTN;
extern void BaniryTreeNodeInit(BTN** root);//初始化
extern BTN* BaniryTreeBuyNode(BaniryTreeData x);//申请节点
extern void BaniryTreePrint(BTN* root);//遍历
extern int  BaniryTreeSizeNode(BTN* root);//节点的个数
extern int  BaniryTreeSizeKNode(BTN* root,int k);//第k层的节点的个数
extern int  BaniryTreeSizeLeaf(BTN* root);//叶子节点的个数
extern int  BaniryTreeDeth(BTN* root);//二叉树的深度
extern BTN* BaniryTreeFindNode(BTN* root, BaniryTreeData x);//查找二叉树的节点 
extern void BaniryTreeStackPrint(BTN* root);//二叉树的层序遍历
extern bool BaniryTreeComplete(BTN* root);//是否为完全二叉树
extern Baniry(void);//总接口