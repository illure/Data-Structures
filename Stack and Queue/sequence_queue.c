#include <stdio.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define MaxSize 50

typedef struct
{
	int data[MaxSize];
	int front, rear;
} SqQueue;

void InitQueue(SqQueue q);
bool isEmpty(SqQueue q);
bool EnQueue(SqQueue q, int x);
bool DeQueue(SqQueue q, int x);

void InitQueue(SqQueue q)
{
	q.front = q.rear = 0;
}

bool isEmpty(SqQueue q)
{
	if (q.front = q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EnQueue(SqQueue q, int x)
{
	if ((q.rear + 1) % MaxSize == q.front)
	{
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}

bool DeQueue(SqQueue q, int x)
{
	if (q.rear == q.front)
	{
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}
