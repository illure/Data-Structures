#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct BiTNode
{
	int data;
	struct BiTNode * lchild, *rchild;
}BiTNode, *BiTree;

void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);
BiTree CreateBiTree(BiTree T);

int linked_binary_tree_main()
{
	BiTree T = NULL;
	T = CreateBiTree(T);
	PreOrder(T);
}

void PreOrder(BiTree T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		if (T->lchild != NULL)
		{
			PreOrder(T->lchild);
		}
		if (T->rchild != NULL)
		{
			PreOrder(T->rchild);
		}
	}
}
void InOrder(BiTree T)
{
	if (T != NULL)
	{
		if (T->lchild != NULL)
		{
			InOrder(T->lchild);
		}
		printf("%d ", T->data);
		if (T->rchild != NULL)
		{
			InOrder(T->rchild);
		}
	}
}
void PostOrder(BiTree T)
{
	if (T != NULL)
	{
		if (T->lchild != NULL)
		{
			PostOrder(T->lchild);
		}
		if (T->rchild != NULL)
		{
			PostOrder(T->rchild);
		}
		printf("%d ", T->data);
	}
}

BiTree CreateBiTree(BiTree T)
{
	int temp;

	scanf("%d", &temp);
	if (temp)
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		if (T == NULL)
		{
			exit(-1);
		}
		T->data = temp;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	else
	{
		T = NULL;
	}
	return T;
}