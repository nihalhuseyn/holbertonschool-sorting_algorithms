#include "sort.h"

/**
 * quick_sort - Sorts an array using Quick Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	int *whole_array;
	size_t full_size;

	if (array == NULL)
		return;

	whole_array = &array[0];
	full_size = size;

	quick_sort_really(array, size, whole_array, full_size);
}

/**
 * quick_sort_really - Recursively sorts subarrays using partition
 * @array: The subarray to sort
 * @size: Size of the subarray
 * @whole_array: Pointer to the original array
 * @full_size: Size of the original array
 */
void quick_sort_really(int *array, size_t size,
		       int *whole_array, size_t full_size)
{
	size_t part;

	if (size > 1)
	{
		part = partitioner(array, size, whole_array, full_size);
		quick_sort_really(&array[0], part, whole_array, full_size);
		quick_sort_really(&array[part], size - part,
				  whole_array, full_size);
	}
}

/**
 * partitioner - Partitions the array using a pivot
 * @array: The subarray to partition
 * @size: Size of the subarray
 * @whole_array: Pointer to the original array
 * @full_size: Size of the original array
 *
 * Return: Index where the array is split
 */
size_t partitioner(int *array, size_t size,
		   int *whole_array, size_t full_size)
{
	int pivot, temp;
	long front, end;

	pivot = array[size - 1];
	front = -1;
	end = size;

	while (1)
	{
		do {
			front++;
		} while (array[front] < pivot);

		do {
			end--;
		} while (array[end] > pivot);

		if (front >= end)
			return ((size_t)front);

		temp = array[front];
		array[front] = array[end];
		array[end] = temp;

		print_array(whole_array, full_size);
	}

	return (end);
}
