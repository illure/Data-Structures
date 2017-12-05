#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct
{
	LinkNode *front, *rear;
}LinkQueue;


void InitQueue(LinkQueue Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue Q, int x);
bool DeQueue(LinkQueue Q, int x);

int main(void)
{


	return 0;
}

void InitQueue(LinkQueue Q)
{
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void EnQueue(LinkQueue Q, int x)
{
	LinkNode * s;
	s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

bool DeQueue(LinkQueue Q, int x)
{
	LinkNode * p;

	if (Q.front == Q.rear)
	{
		return false;
	}
	p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.rear == Q.front;
	}
	free(p);
	return true;

}


