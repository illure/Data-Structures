#include <stdio.h>

#pragma warning(disable:4996)

typedef struct ThreadNode
{
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
} ThreadNode, *ThreadTree;

void InThread(ThreadTree p, ThreadTree pre);   //通过中序遍历对二叉树线索化的递归算法
void CreateInThread(ThreadTree T);			   //通过中序遍历建立中序线索二叉树
ThreadNode *FirstNode(ThreadNode *p);		   //返回中序线索二叉树中中序序列下的第一个结点
ThreadNode *NextNode(ThreadNode *p);		   //返回中序线索二叉树中节点p在中序序列下的后继结点
void InOrderThread(ThreadNode *T);			   //不含头结点的中序线索二叉树的中序遍历的算法

void InThread(ThreadTree p, ThreadTree pre)
{
	if (p != NULL)
	{
		InThread(p->lchild, pre);
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}

void CreateInThread(ThreadTree T)
{
	ThreadTree pre = NULL;
	if (T != NULL)
	{
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

ThreadNode *FirstNode(ThreadNode *p)
{
	while (p->ltag == 0)
	{
		p = p->lchild;
	}
	return p;
}

ThreadNode *NextNode(ThreadNode *p)
{
	if (p->rtag == 0)
	{
		return FirstNode(p->rchild);
	}
	else
	{
		return p->rchild;
	}
}

void InOrderThread(ThreadNode *T)
{
	for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
	{
		printf("%d  ", p);
	}
}