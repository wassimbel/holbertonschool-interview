#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: pointer to the head of the skip list to search in
 * @value: the value to search for
 * Return: return a pointer on the first node where value is located or NULL
 **/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp, *prev;

	if (!list)
		return (NULL);
	tmp = list->express;
	prev = list;

	while (tmp)
	{
		printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
		if (value <= tmp->n)
			break;
		prev = tmp;

		if (!tmp->express)
		{
			while (tmp->next)
				tmp = tmp->next;
			break;
		}
		tmp = tmp->express;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		 prev->index, tmp->index);

	while (prev && prev->index <= tmp->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
