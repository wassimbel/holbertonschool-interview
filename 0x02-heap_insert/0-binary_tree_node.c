#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: pointer to the new node or null on failure
 **/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *bt;

	bt = malloc(sizeof(binary_tree_t));
	if (!bt)
		return (NULL);
	bt->n = value;
	bt->parent = parent;
	bt->left = NULL;
	bt->right = NULL;
	return (bt);
}
