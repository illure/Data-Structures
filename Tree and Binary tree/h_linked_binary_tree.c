#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

struct BTNode
{
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
};

struct BTNode *CreateBTree();
void PreTraverseBTree(struct BTNode *pT);
void InTraverseBTree(struct BTNode *pT);
void PostTraverseBTree(struct BTNode *pT);

int h_linked_binary_tree_main()
{
	struct BTNode *pT = CreateBTree();  //静态初始化二叉树
	PreTraverseBTree(pT);				//先序遍历
	InTraverseBTree(pT);				//中序遍历
	PostTraverseBTree(pT);				//后序遍历

	return 0;
}

struct BTNode *CreateBTree()
{
	struct BTNode *pA = (struct BTNode *) malloc(sizeof(struct BTNode));
	struct BTNode *pB = (struct BTNode *) malloc(sizeof(struct BTNode));
	struct BTNode *pC = (struct BTNode *) malloc(sizeof(struct BTNode));
	struct BTNode *pD = (struct BTNode *) malloc(sizeof(struct BTNode));
	struct BTNode *pE = (struct BTNode *) malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}

void PreTraverseBTree(struct BTNode *pT)
{
	if (pT != NULL)
	{
		printf("%c\n", pT->data);
		if (pT->pLchild != NULL)
		{
			PreTraverseBTree(pT->pLchild);
		}
		if (pT->pRchild != NULL)
		{
			PreTraverseBTree(pT->pRchild);
		}	
	}
}

void InTraverseBTree(struct BTNode *pT)
{
	if (pT != NULL)
	{
		if (pT->pLchild != NULL)
		{
			InTraverseBTree(pT->pLchild);
		}
		printf("%c\n", pT->data);
		if (pT->pRchild != NULL)
		{
			InTraverseBTree(pT->pRchild);
		}
	}
}

void PostTraverseBTree(struct BTNode *pT)
{
	if (pT != NULL)
	{
		if (pT->pLchild != NULL)
		{
			PostTraverseBTree(pT->pLchild);
		}
		if (pT->pRchild != NULL)
		{
			PostTraverseBTree(pT->pRchild);
		}
		printf("%c\n", pT->data);
	}
}