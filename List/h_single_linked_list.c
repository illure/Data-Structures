#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma warning(disable:4996)

typedef struct Node
{
	int data; //数据域
	struct Node * pNext; //指针域
}NODE, *PNODE; //NODE等价于struct Node  PNODE等价于struct Node *

PNODE create_list(void); //创建链表
void traverse_list(PNODE pHead); //遍历链表
bool is_empty(PNODE pHead); // 判断链表是否为空
int length_list(PNODE); // 求链表长度
void sort_list(PNODE); //对链表进行排序
bool insert_list(PNODE pHead, int pos, int val); //在pHead所指向链表的第pos个节点的前面插入一个新的结点，该节点的值是val， 并且pos的值是从1开始
bool delete_list(PNODE pHead, int pos, int * pVal); //删除链表第pos个节点，并将删除的结点的值存入pVal所指向的变量中,  并且pos的值是从1开始

int h_single_linked_list_main(void)
{
	PNODE pHead = NULL;
	int val;

	pHead = create_list(); //create_list()功能：创建一个非循环单链表，并将该链表的头结点的地址付给pHead
	traverse_list(pHead);

	return 0;
}

PNODE create_list(void)
{
	int len; //用来存放有效节点的个数
	int i;
	int val; //用来临时存放用户输入的结点的值

			 //分配了一个不存放有效数据的头节点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败，程序终止\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入您需要生成的链表结点的个数： len = ");
	scanf("%d", &len);

	for (i = 0; i < len; i++)
	{
		printf("请输入第%d个结点的值：", i + 1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("分配失败，程序终止\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;

	while (NULL != p)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;

	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < len; ++j, q = q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}

	return;
}

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p)
	{
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态内存分配失败！\n");
	}
	pNew->data = val;

	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}

bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p->pNext)
	{
		return false;
	}

	PNODE q = p->pNext;    //q指向待删除的结点
	*pVal = q->data;

	//删除p结点后面的结点
	p->pNext = p->pNext->pNext;

	//释放内存
	free(q);
	q = NULL;

	return true;

}
