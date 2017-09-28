#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList CreateList1(LinkList L);				//头插法
LinkList CreateList2(LinkList L);				//尾插法
LNode *GetElem(LinkList L, int i);				//按序号查找节点值
LNode *LocateElem(LinkList L, int e);			//按值查找表结点
void TraverseList(LinkList L);					//遍历
void NodeInsert(LinkList L, int x, int i);		//插入结点
void NodeDelete(LinkList L, int x);				//删除结点

#pragma warning(disable:4996)
int main()
{
	LinkList linkList = NULL;

	//linkList = CreateList1(linkList);
	linkList = CreateList2(linkList);

	TraverseList(linkList);
	printf("\n");
	printf("------------------------\n");

	LNode *p;
	int data;
	p = GetElem(linkList, 4);
	data = p->data;
	printf("按序号查找值：%d", data);
	printf("\n");
	printf("------------------------\n");
	p = LocateElem(linkList, 55);
	LNode *q = linkList->next;
	int number = 1;
	while (q != NULL)
	{
		if (q != p)
		{
			number++;
			q = q->next;
		}
		else
		{
			break;
		}
	}
	printf("按值查找结点：第%d个结点", number);
	printf("\n");
	printf("------------------------\n");
	//NodeInsert(linkList, 12345, 3);
	printf("\n");
	printf("------------------------\n");

	getchar();
	return 0;
}

LinkList CreateList1(LinkList L)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

LinkList CreateList2(LinkList L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

LNode *GetElem(LinkList L, int i)
{
	int j = 1;
	LNode *p = L->next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

LNode *LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}

void TraverseList(LinkList L)
{
	LNode *p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void NodeInsert(LinkList L, int x, int i)
{
	LNode *p = L->next;
	LNode *s, *q;
	if (p = NULL)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		p = s;
	}
	else
	{
		if (i = 1)
		{
			if (p->next = NULL)
			{
				s = (LNode *)malloc(sizeof(LNode));
				s->data = x;
				s->next = p;
				p = s;
			}
			else
			{
				q = GetElem(L, i);
				s = (LNode *)malloc(sizeof(LNode));
				s->data = x;
				s->next = q->next;
				q->next = s;
			}
		}
		else
		{
			q = GetElem(L, i);
			s = (LNode *)malloc(sizeof(LNode));
			s->data = x;
			s->next = q->next;
			q->next = s;
		}
	}
}

void NodeDelete(LinkList L, int x)
{

}