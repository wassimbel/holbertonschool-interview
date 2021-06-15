#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - checks if a given number is a palindrome
 * @n: number to check
 * Return: returns 1 if palindrome otherwise 0
 **/

int is_palindrome(unsigned long n)
{
	int i, j, len;
	int array[10000];

	for (i = 0; n != 0; i++)
	{
		array[i] = n % 10;
		n = n / 10;
	}
	len = i;
	j = len - 1;

	if (len == 1)
		return (1);
	if (len % 2 == 0)
	{
		for (i = 0; i <= (len - 1) / 2; i++, j--)
		{
			if (array[i] == array[j])
				return (1);
		}
	}
	j = len - 1;

	for (i = 0; i <= (len - 2) / 2; i++, j--)
	{
		if (array[i] == array[j])
			return (1);
	}
	return (0);
}
