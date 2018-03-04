#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable:4996)

#define INSERTION_SORT_N 6

void bubble_sort_test();
void bubble_sort(int *a, int n);

int bubble_sort_main()
{
	bubble_sort_test();
	return 0;
}

void bubble_sort_test()
{
	int i;
	int a[INSERTION_SORT_N] = { 5, 2, 4, 6, 1, 3 };
	bubble_sort(a, INSERTION_SORT_N);
	for (i = 0; i < INSERTION_SORT_N; i++)
	{
		printf("%d ", a[i]);
	}
}

void bubble_sort(int *a, int n)
{
	int i, j, key;
	bool flag;

	for (i = 0; i < n - 1; i++)
	{
		flag = false;
		for (j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				key = a[j - 1];
				a[j - 1] = a[j];
				a[j] = key;
				flag = true;
			}
		}
		if (flag == false)
		{
			return;
		}
	}
}