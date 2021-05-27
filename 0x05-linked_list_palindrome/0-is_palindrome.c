#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the linked list
 * Return: 1 if linked list is palindrome otherwise 0
 **/

int is_palindrome(listint_t **head)
{
	listint_t *current;
	int left[1000], right[1000], i, j, k;

	current = *head;


	if (*head == NULL)
		return (1);

	while (current->next != NULL)
	{
		left[i] = current->n;
		current = current->next;
		i++;
	}

	left[i] = current->n;
	k = i + 1;

	for (; j < k; j++, i--)
	{
		right[j] = left[i];
	}

	for (i = 0; i < k; i++)
	{
		if (left[i] != right[i])
			return (0);
	}
	return (1);
}
