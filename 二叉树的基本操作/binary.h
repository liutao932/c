#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char BinaryNodeType;

typedef struct BinaryTreeNode
{
	BinaryNodeType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* rigth;
}BTNode;

BTNode* BuyNode(BinaryNodeType x); //创建节点
void BTNodeCreat(BTNode* ); //创建二叉树
void BTNodeFront(BTNode* root); //前序遍历
void BTNodeMid(BTNode* root);//中序遍历
void BTNodeBehind(BTNode* root); //后续遍历
int BTNodeSize(BTNode* root); //二叉树节点的个数
int BTNodeSizeLeaf(BTNode* root); //二叉树叶子节点的个数
int BTNodeSizeK(BTNode* root, int k);//二叉树第K层的节点个数
int BTNodeDeth(BTNode* root);//二叉树的深度
BTNode* BTNodeFind(BTNode* root, BinaryNodeType x);//查找值为x的节点