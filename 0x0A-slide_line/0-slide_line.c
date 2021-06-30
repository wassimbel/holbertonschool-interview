#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers containing size elements
 * @size: size of line array
 * @direction: direction to slide and merge to
 * Return: 1 upon success, or 0 upon failure
 **/

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	return (slide_right(line, size));
}

/**
 * slide_left - slides and merges to the left
 * @line: array of integers containing size elements
 * @size: size of line array
 * Return: 1 upon success, or 0 upon failure
 **/

int slide_left(int *line, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int tmp1 = 0;
	int tmp2 = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && tmp1 == 0)
			tmp1 = line[i];
		else if (line[i] != 0 && tmp1 != 0)
			tmp2 = line[i];
		if (tmp1 != 0 && tmp2 != 0)
		{
			if (tmp1 == tmp2)
			{
				line[j] = tmp1 + tmp2;
				tmp1 = 0;
				tmp2 = 0;
				j++;
			}
			else
			{
				line[j] = tmp1;
				tmp1 = tmp2;
				tmp2 = 0;
				j++;
				if (i == size - 1)
				{
					line[j] = tmp1;
					j++;
				}
			}
		}
		else if (tmp1 != tmp2 && i == size - 1)
		{
			line[j] = tmp1;
			j++;
		}
	}
	for (i = j; i < size; i++)
	{
		line[i] = 0;
	}
	return (1);
}

/**
 * slide_right - slides and merges to the right
 * @line: array of integers containing size elements
 * @size: size of line array
 * Return: 1 upon success, or 0 upon failure
 **/

int slide_right(int *line, size_t size)
{
	size_t i = 0;
	size_t j = size - 1;
	int tmp1 = 0;
	int tmp2 = 0;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && tmp1 == 0)
			tmp1 = line[i];
		else if (line[i] != 0 && tmp1 != 0)
			tmp2 = line[i];
		if (tmp1 != 0 && tmp2 != 0)
		{
			if (tmp1 == tmp2)
			{
				line[j] = tmp1 + tmp2;
				tmp1 = 0;
				tmp2 = 0;
				j--;
			}
			else
			{
				line[j] = tmp1;
				tmp1 = tmp2;
				tmp2 = 0;
				j--;
				if (i == 0)
				{
					line[j] = tmp1;
					j--;
				}
			}
		}
		else if (tmp1 != tmp2 && i == 0)
		{
			line[j] = tmp1;
			j--;
		}
	}
	for (i = 0; i < j + 1; i++)
	{
		line[i] = 0;
	}
	return (1);
}
