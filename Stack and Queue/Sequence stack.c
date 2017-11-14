#include <stdio.h>

#define MaxSize 50

typedef struct SqStack
{
	int data[MaxSize];
	int top;
} SqStack;

void InitStack(SqStack &S);							//��ʼ��
bool StackEmpty(SqStack S);							//�ж�ջ��
bool Push(SqStack &S, int x);						//��ջ
bool Pop(SqStack &S, int &x);						//��ջ
bool GetTop(SqStack S, int &x);						//��ջ��Ԫ��

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