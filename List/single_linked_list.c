#include <stdio.h>
#include <stdlib.h>

typedef struct LNode							//���	
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList CreateList1(LinkList L);				//ͷ�巨
LinkList CreateList2(LinkList L);				//β�巨
LNode *GetElem(LinkList L, int i);				//����Ų��ҽڵ�ֵ
LNode *LocateElem(LinkList L, int e);			//��ֵ���ұ���
void TraverseList(LinkList L);					//����
LinkList NodeInsert(LinkList L, int e, int i);	//������
void NodeDelete(LinkList L, int e);				//��ֵɾ�����

#pragma warning(disable:4996)
int main()
{
	LinkList linkList = NULL;

	//linkList = CreateList1(linkList);
	linkList = CreateList2(linkList);

	TraverseList(linkList);
	printf("\n------------------------\n");

	LNode *p;
	int data;
	p = GetElem(linkList, 4);
	data = p->data;
	printf("����Ų���ֵ��%d", data);
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
	printf("��ֵ���ҽ�㣺��%d�����", number);
	printf("\n------------------------\n");

	printf("\n--�ڵ�1��λ�ò���ֵ111--\n");
	linkList = NodeInsert(linkList, 111, 1);
	TraverseList(linkList);
	printf("\n------------------------\n");

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

LinkList NodeInsert(LinkList L, int e, int i)
{
	LNode *s;
	LNode *p = L->next;
	int count = 0;
	while (p != NULL)
	{
		count += 1;
		if (i == 1 && count == 1) {
			s = (LNode *)malloc(sizeof(LNode));
			s->data = e;
			s->next = p;
			L->next = s;
			return L;
		}
		else
		{
			if (count == i - 1)
			{
				s = (LNode *)malloc(sizeof(LNode));
				s->data = e;
				s->next = p->next;
				p->next = s;
				return L;
			}
		}

		p = p->next;
	}
}

void NodeDelete(LinkList L, int e)  //����֤
{
	LNode * p = LocateElem(L, e);
	LNode * q = L->next;
	LNode * left;
	if (q = p)
	{
		L->next = q->next;
	}
	while (q->next != NULL)
	{
		if (q->next = p)
		{
			q->next = p->next;
		}
		else
		{
			q = q->next;
		}
	}
}