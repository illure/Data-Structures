#include <stdio.h>
#pragma warning(disable:4996)

#define INSERTION_SORT_N 6

void direct_insertion_sort_test();
void direct_insertion_sort(int *a, int n);

int direct_insertion_sort_main()
{
	direct_insertion_sort_test();

	return 0;
}

void direct_insertion_sort_test()
{
	int i;
	int a[INSERTION_SORT_N] = { 5, 2, 4, 6, 1, 3 };
	direct_insertion_sort(a, INSERTION_SORT_N);
	for (i = 0; i < INSERTION_SORT_N; i++)
	{
		printf("%d ", a[i]);
	}
}

void direct_insertion_sort(int *a, int n)
{
	int i, j, key;
	for (j = 1; j < n; j++)
	{
		key = a[j];
		if (a[j] < a[j - 1])
		{
			for (i = j - 1; i >= 0, key < a[i]; i--)
			{
				a[i + 1] = a[i];
			}
			a[i + 1] = key;
		}
	}
}