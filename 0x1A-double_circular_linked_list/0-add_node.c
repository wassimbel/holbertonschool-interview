#include "list.h"

/**
 * create_node - creates a new node
 * @str: the string to copy into the new node
 * Return: Returns: Address of the new node, or NULL on failure
 **/
List *create_node(char *str)
{
	List *new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node->str);
		return (NULL);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Returns: Address of the new node, or NULL on failure
 **/

List *add_node_end(List **list, char *str)
{
	List *last_node, *new_node;

	new_node = create_node(str);
	if (!new_node)
		return (NULL);

	if (!(*list))
	{
		*list = new_node;
		new_node->prev = new_node->next = new_node;
	}
	else
	{
		last_node = (*list)->prev;
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - Add a new node to the beggining
 * of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Returns: Address of the new node, or NULL on failure
 **/

List *add_node_begin(List **list, char *str)
{
	List *last_node, *new_node;

	new_node = create_node(str);
	if (!new_node)
		return (NULL);

	if (!(*list))
	{
		*list = new_node;
		new_node->prev = new_node->next = new_node;
	}
	else
	{
		last_node = (*list)->prev;
		last_node->next = new_node;
		new_node->next = *list;
		new_node->prev = last_node;
		(*list)->prev = new_node;
		*list = new_node;
	}
	return (new_node);
}
