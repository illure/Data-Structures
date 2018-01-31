#include <stdio.h>

#pragma warning(disable:4996)

typedef struct DNode
{
	int data;
	struct DNode *prior, *next;
}DNode, *DLinklist;