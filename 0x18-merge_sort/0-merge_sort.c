#include "sort.h"

/**
 * merge_sort - sift_down merge
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *copy = NULL;

	if (!array || size == 1)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	sift_down(array, size, copy);
	free(copy);
}

/**
 * merge - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * @mid: middle element
 * @copy: a copy of the array
 * Return: void
 */

void merge(int *array, int size, int mid, int *copy)
{
	int i = 0, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);
	for (k = 0; k < size; k++)
	{

		if (j == size)
		{
			copy[k] = array[i];
			i++;
		}
		else if (i == mid)
		{
			copy[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			copy[k] = array[j];
			j++;
		}
		else
		{
			copy[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = copy[i];
	}
	printf("[Done]: ");
	print_array(copy, size);
}


/**
 * sift_down - sorts using sift_down
 * @array: Array to be sorted
 * @size: Size of the array
 * @copy: copy of the array
 * Return: void
 */
void sift_down(int *array, size_t size, int *copy)
{
	int mid;

	if (size == 1)
		return;
	mid = size / 2;
	sift_down(array, mid, copy);
	sift_down(array + mid,  size - mid, copy);
	merge(array, size, mid, copy);
}
