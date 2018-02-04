#include <stdio.h>
#pragma warning(disable:4996)

#define INSERTION_SORT_N 6

void shell_sort_test();
void shell_sort(int *a, int n);

int shell_sort_main()                                               //Ï£¶ûÅÅÐò
{
	shell_sort_test();

	return 0;
}

void shell_sort_test()
{
	int i;
	int a[INSERTION_SORT_N] = {5, 2, 4, 6, 1, 3 };
	shell_sort(a, INSERTION_SORT_N);
	for (i = 0; i < INSERTION_SORT_N; i++)
	{
		printf("%d ", a[i]);
	}
}

void shell_sort(int *a, int n)
{
	int dk, i, j, key;
	for ( dk = n / 2; dk >= 1; dk /= 2)
	{
		for ( i = dk; i < n; i++)
		{
			if (a[i] < a[i - dk])
			{
				key = a[i];
				for ( j = i - dk; j >= 0 && key < a[j]; j -= dk)
				{
					a[j + dk] = a[j];
				}
				a[j + dk] = key;
			}
		}
	}
}