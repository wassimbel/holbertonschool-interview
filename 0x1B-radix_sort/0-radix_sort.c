#include "sort.h"

/**
 * sort - sorts an array
 * @array: pointer to array to be sorted
 * @size: size of the @array
 * @n: integer
 * Return: returns void
 */
void sort(int *array, size_t size, int n)
{
	int arr[10] = {0}, j, *buff;
	size_t i;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;
	for (i = 0; i < size; i++)
		arr[(array[i] / n) % 10]++;
	for (i = 1; i < 10; i++)
		arr[i] += arr[i - 1];
	for (j = size - 1; j >= 0; j--)
	{
		buff[arr[(array[j] / n) % 10] - 1] = array[j];
		arr[(array[j] / n) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = buff[i];
	print_array(array, size);
	free(buff);
}

/**
 * radix_sort -  sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of the array
 * Return: returns void
 */
void radix_sort(int *array, size_t size)
{
	int j = 1, max;
	size_t i;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max)
	{
		sort(array, size, j);
		j *= 10;
		max /= 10;
	}
}
