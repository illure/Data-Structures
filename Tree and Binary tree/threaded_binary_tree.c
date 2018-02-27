#include <stdio.h>

#pragma warning(disable:4996)

typedef struct ThreadNode
{
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
} ThreadNode, *ThreadTree;

void InThread(ThreadTree p, ThreadTree pre);   //ͨ����������Զ������������ĵݹ��㷨
void CreateInThread(ThreadTree T);			   //ͨ���������������������������
ThreadNode *FirstNode(ThreadNode *p);		   //�����������������������������µĵ�һ�����
ThreadNode *NextNode(ThreadNode *p);		   //�������������������нڵ�p�����������µĺ�̽��
void InOrderThread(ThreadNode *T);			   //����ͷ������������������������������㷨

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