#include <stdio.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define MaxSize 50

typedef struct
{
	int data[MaxSize];
	int front, rear;
} SqQueue;

