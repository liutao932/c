#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char BaniryTreeData;

typedef struct BaniryTreeNode
{
	BaniryTreeData data;
	struct BaniryTreeNode* LeftChild;
	struct BaniryTreeNode* RigthChild;
}BTNode;

BTNode* BuyNode(BaniryTreeData x);
void BTNodeCreat(BTNode ** root);
void BTNodePrint(BTNode* root);
int BTNodeSize(BTNode* root);
int BTNodeSizeLeaf(BTNode* root);
int BTNodeSizeK(BTNode* root,int k);
int BTNodeDeth(BTNode* root);
BTNode* BTNodeFind(BTNode* root, BaniryTreeData x);