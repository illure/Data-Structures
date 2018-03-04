#include <stdio.h>
#pragma warning(disable:4996)

#define INSERTION_SORT_N 6

void select_sort_test();
void select_sort(int *a, int n);

int select_sort_main()
{
	select_sort_test();

	return 0;
}

void select_sort_test()
{
	int i;
	int a[INSERTION_SORT_N] = { 5, 2, 4, 6, 1, 3 };
	select_sort(a, INSERTION_SORT_N);
	for (i = 0; i < INSERTION_SORT_N; i++)
	{
		printf("%d ", a[i]);
	}
}

void select_sort(int *a, int n)
{
	int i, min, j, key;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for ( j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			key = a[i];
			a[i] = a[min];
			a[min] = key;
		}
	}
}