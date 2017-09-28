#include <stdio.h>

#define MaxSize 50

typedef struct SqStack
{
	int data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack &S);							//³õÊ¼»¯
bool StackEmpty(SqStack S);							//ÅÐ¶ÏÕ»¿Õ
bool Push(SqStack &S, int x);						//½øÕ»
bool Pop(SqStack &S, int &x);						//³öÕ»
bool GetTop(SqStack S, int &x);						//¶ÁÕ»¶¥ÔªËØ

int main()
{

}

void InitStack(SqStack &S)
{
	S.top = -1;
}

bool StackEmpty(SqStack S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}

bool Push(SqStack &S, int x)
{
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;

	return true;
}

bool Pop(SqStack &S, int &x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top--];

	return true;
}

bool GetTop(SqStack S, int &x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top];

	return true;
}