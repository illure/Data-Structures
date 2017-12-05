#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
void clear(PSTACK pS);

int main(void)
{
	return 0;
}

void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));

	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;

	return;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;

	while (p != pS->pBottom)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}