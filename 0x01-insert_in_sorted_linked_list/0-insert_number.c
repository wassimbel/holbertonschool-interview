#include "lists.h"

/**
 * insert_node - Inserts a node into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current;

	current = *head;
	new_node = malloc(sizeof(listint_t));
	if (new_node)
	{
		new_node->n = number;
		new_node->next = NULL;
		if (*head == NULL || (*head)->n > new_node->n)
			*head = new_node;
		else
		{
			while (current->next && current->next->n < new_node->n)
				current = current->next;
			new_node->next = current->next;
			current->next = new_node;
		}
		return (new_node);
	}
	return (NULL);
}
