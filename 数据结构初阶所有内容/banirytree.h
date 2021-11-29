#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char BaniryTreeDataType;

typedef struct BaniryTreeNode
{
	BaniryTreeDataType data;
	struct BaniryTreeNode* left;
	struct BaniryTreeNode* rigth;
}BT;

BT* BaniryTreeBuyNode(BaniryTreeDataType x);
void BaniryTreeInit(BT** root);
void BaniryPrintFront(BT* root);
void BaniryPrintMid(BT* root);
void BaniryPrintBehind(BT* root);
int BaniryTreeSize(BT* root);
int BaniryTreeSizeLeaf(BT* root);
int BaniryTreeSizeK(BT* root,int k);
int BaniryTreeDeth(BT* root);
BT* BaniryFind(BT* root);
void BaniryStackPrint(BT* root);