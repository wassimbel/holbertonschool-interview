#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>


avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array)
		return (NULL);

	root = sort(NULL, array, 0, size - 1);
	return (root);
}

avl_t *sort(avl_t *parent, int *array, int start, int end)
{
	int mid = (start + end) / 2;

	avl_t *root;

	if (start > end)
		return (NULL);

	root = new_node(parent, array[mid]);
		if (!root)
			return (NULL);
	root->left = sort(root, array, start, mid - 1);
	root->right = sort(root, array, mid + 1, end);
	return (root);
}

avl_t *new_node(avl_t *parent, int n)
{
	avl_t *new_node;
	new_node = (avl_t*)malloc(sizeof(avl_t));

	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = n;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
