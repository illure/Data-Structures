#include <stdio.h>
#include <stdlib.h>

typedef struct LNode							//结点	
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList CreateList1(LinkList L);				//头插法
LinkList CreateList2(LinkList L);				//尾插法
LNode *GetElem(LinkList L, int i);				//按序号查找节点值
LNode *LocateElem(LinkList L, int e);			//按值查找表结点
void TraverseList(LinkList L);					//遍历
void NodeInsert(LinkList L, int e, int i);		//插入结点
void NodeDelete(LinkList L, int e);				//按值删除结点

#pragma warning(disable:4996)
int main()
{
	LinkList linkList = NULL;

	//linkList = CreateList1(linkList);
	linkList = CreateList2(linkList);

	TraverseList(linkList);

	printf("\n------------------------\n");
	LNode *p;
	p = GetElem(linkList, 4);
	printf("按序号4查找值：%d", p->data);

	printf("\n------------------------\n");
	p = GetElem(linkList, 1);
	printf("按序号1查找值：%d", p->data);

	printf("\n------------------------\n");
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
	printf("按值55查找结点：第%d个结点", number);

	printf("\n------------------------\n");
	p = LocateElem(linkList, 11);
	q = linkList->next;
	number = 1;
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
	printf("按值11查找结点：第%d个结点", number);

	printf("\n------------------------\n");
	printf("\n--在第1个位置插入值111--\n");
	NodeInsert(linkList, 111, 1);
	TraverseList(linkList);

	printf("\n------------------------\n");
	printf("\n--在第3个位置插入值222--\n");
	NodeInsert(linkList, 222, 3);
	TraverseList(linkList);

	printf("\n------------------------\n");
	printf("\n----删除值为111的结点---\n");
	NodeDelete(linkList, 111);
	TraverseList(linkList);

	printf("\n------------------------\n");
	printf("\n----删除值为222的结点---\n");
	NodeDelete(linkList, 222);
	TraverseList(linkList);

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

void NodeInsert(LinkList L, int e, int i)
{
	if (i == 1)
	{
		LNode * s;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L->next;
		L->next = s;
	}
	else
	{
		LNode * p = GetElem(L, i - 1);
		LNode * q = p->next;
		LNode * s;
		s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		p->next = s;
		s->next = q;
	}
}

void NodeDelete(LinkList L, int e)
{
	LNode * p = LocateElem(L, e);
	LNode * q = L->next;
	if (p == q)
	{
		L->next = p->next;
		free(p);
	}
	else
	{
		while (q != NULL && q->next != NULL && q->next != p)
		{
			q = q->next;
		}
		q->next = p->next;
		free(p);
	}
}