#include <stdio.h>
#include <stdbool.h>
#define MaxSize 50
#pragma warning(disable:4996)

typedef struct {
	int data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack S);
bool StackEmpty(SqStack S);
bool Push(SqStack S, int x);
bool Pop(SqStack s, int x);
bool GetTop(SqStack s, int x);



void InitStack(SqStack s)
{
	s.top = -1;
}

bool StackEmpty(SqStack s)
{
	if (s.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Push(SqStack s, int x)
{
	if (s.top == MaxSize - 1)
	{
		return false;
	}
	s.data[++s.top] = x;
	return true;
}

bool Pop(SqStack s, int x)
{
	if (s.top == -1)
	{
		return false;
	}
	x = s.data[s.top--];
	return true;
}

bool GetTop(SqStack s, int x)
{
	if (s.top == -1)
	{
		return false;
	}
	x = s.data[s.top];
	return true;
}












