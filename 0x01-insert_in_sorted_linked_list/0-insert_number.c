#include "lists.h"

/**
* insert_node - inster number into a sorted singly linked lists
* @head: pointer to pointer of first node of listint_t list
* @number: integer
* Return: address of added node or NULL if it fails
*/


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current, *new_node;

	current = *head;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL || head == NULL)
		*head = new_node;
	else
	{
		if ((*head)->next == NULL && (*head)->n > number)
		{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
		}
		while (current->next != NULL)
		{
			if (current->next->n > number)
			{
				new_node->next = current->next;
				current->next = new_node;
				return (new_node);
			}
			current = current->next;
		}
		current->next = new_node;
	}
	return (new_node);
}
