#include <stdio.h>
#pragma warning(disable:4996)

#define INSERTION_SORT_N 6

void merge_sort_test();
void merge(int *a, int low, int mid, int high);
void merge_sort(int *a, int low, int high);

int merge_sort_main()
{
	merge_sort_test();
	return 0;
}

void merge_sort_test()
{
	int i;
	int a[INSERTION_SORT_N] = { 5, 2, 4, 6, 1, 3 };
	merge_sort(a, 1, 6);
	for (i = 0; i < INSERTION_SORT_N; i++)
	{
		printf("%d ", a[i]);
	}
}

void merge(int *a, int low, int mid, int high)
{
	int i, j, k;
	int b[INSERTION_SORT_N];
	for (k = low - 1; k < high; k++)
	{
		b[k] = a[k];
	}
	for ( i = low - 1, j = mid, k = i; i < mid && j < high; k++)
	{
		if (b[i] < b[j])
		{
			a[k] = b[i++];
		}
		else
		{
			a[k] = b[j++];
		}
	}
	while (i < mid)
	{
		a[k++] = b[i++];
	}
	while (j < high)
	{
		a[k++] = b[j++];
	}
}

void merge_sort(int *a, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}