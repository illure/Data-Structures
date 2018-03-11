#include <stdio.h>
#pragma warning(disable:4996)

#define INSERTION_SORT_N 7

void BuildMaxHeap(int *a, int len);
void AdjustDown(int *a, int k, int len);
void HeapSort(int *a, int len);
void AdjustUp(int *a, int k);
void heap_sort_test();

int main()
{
	heap_sort_test();
	return 0;
}

void heap_sort_test()
{
	int i;
	int a[INSERTION_SORT_N] = { 0, 5, 2, 4, 6, 1, 3 };
	HeapSort(a, INSERTION_SORT_N - 1);
	for (i = 1; i < INSERTION_SORT_N; i++)
	{
		printf("%d ", a[i]);
	}
}

void BuildMaxHeap(int *a, int len)
{
	for (int i = len / 2; i > 0; i--)
	{
		AdjustDown(a, i, len);
	}
}

void AdjustDown(int *a, int k, int len)
{
	a[0] = a[k];
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && a[i] < a[i + 1])
		{
			i++;
		}
		if (a[0] >= a[i])
		{
			break;
		}
		else
		{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0];
}

void HeapSort(int *a, int len)
{
	int key;
	BuildMaxHeap(a, len);
	for (int i = len; i > 1; i--)
	{
		key = a[i];
		a[i] = a[1];
		a[1] = key;
		AdjustDown(a, 1, i - 1);
	}
}

void AdjustUp(int *a, int k)
{
	a[0] = a[k];
	int i = k / 2;
	while (i > 0 && a[i] < a[0])
	{
		a[k] = a[i];
		k = i;
		i = k / 2;
	}
	a[k] = a[0];
}