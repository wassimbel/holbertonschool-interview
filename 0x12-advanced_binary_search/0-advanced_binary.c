#include "search_algos.h"

/**
 * advanced_binary -  searches for a value in a sorted array of integers.
 * @array: pointer to first element
 * @size: size of the array
 * @value: value to search for
 * Return: returns index of value or -1 on failure
 **/

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (recursion_search(array, 0, size - 1, value));
}

/**
 * print_array - prints a given array of ints
 * @array: pointer to first element
 * @start: index of first element
 * @end: index of last element
 **/

void print_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursion_search - searches for first occurence of value in array
 * @array: pointer to first element
 * @start: index of first element
 * @end: index of last element
 * @value: value to search for
 * Return: returns index of value or -1 on failure
 **/

int recursion_search(int *array, int start, int end, int value)
{
	int mid;

	print_array(array, start, end);
	if (start == end)
		return (-1);
	if (start <= end)
	{
		mid = start + (end - start) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		else if (array[mid] >= value)
			return (recursion_search(array, start, mid, value));
		else if (array[mid] <= value)
			return (recursion_search(array, mid + 1, end, value));
	}
	return (-1);
}
