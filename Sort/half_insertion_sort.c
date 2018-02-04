#include <stdio.h>
#pragma warning(disable:4996)

#define INSERTION_SORT_N 6

void half_insertion_sort_test();
void half_insertion_sort(int *a, int n);

int half_insertion_sort_main()                            //’€∞Î≤Â»Î≈≈–Ú
{
	half_insertion_sort_test();

	return 0;
}

void half_insertion_sort_test()
{
	int i;
	int a[INSERTION_SORT_N] = { 5, 2, 4, 6, 1, 3 };
	half_insertion_sort(a, INSERTION_SORT_N);
	for (i = 0; i < INSERTION_SORT_N; i++)
	{
		printf("%d ", a[i]);
	}
}

void half_insertion_sort(int *a, int n)
{
	int i, j, key, low, high, mid;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		low = 0;
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] > key)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (j = i - 1; j >= high + 1; j--)
		{
			a[j + 1] = a[j];
		}
		a[high + 1] = key;
	}
}