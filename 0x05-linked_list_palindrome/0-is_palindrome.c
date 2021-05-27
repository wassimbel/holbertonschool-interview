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
	int array[1000];
	int i = 0, j = 0, k = 0;

	current = *head;


	if (*head == NULL)
		return (1);

	while (current != NULL)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}
	k = i - 1;
	for (j = 0; j < (i / 2); j++, k--)
	{
		if (array[j] != array[k])
			return (0);
	}
	return (1);
}
