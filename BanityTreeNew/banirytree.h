#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char BaniryTreeData;
typedef struct BaniryTreeNode
{
	BaniryTreeData data;
	struct BaniryTreeNode* left;
	struct BaniryTreeNode* rigth;
}BTNode;

BTNode* BuyNode(BaniryTreeData x);
void BTNodeInit(BTNode** root);
void PrintFront(BTNode* root);
int BTNodeSize(BTNode* root);
int BTNodeSizeLeaf(BTNode* root);
int BTNodeSizeK(BTNode* root,int k);
int BTNodeDeth(BTNode* root);
BTNode* BTNodeFind(BTNode* root, BaniryTreeData x);