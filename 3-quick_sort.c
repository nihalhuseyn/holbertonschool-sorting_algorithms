#include "sort.h"

/**
 * swap - swaps 2 elements
 * @x: first element
 * @y: second element
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * partition - func
 * @array: var
 * @low: var
 * @high: func
 * @size: func
 * Return: index of p
 */

int partition(int *array, int low, int high, size_t size)
{
	int p = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= p)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_rec - sorts an array
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: var
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
