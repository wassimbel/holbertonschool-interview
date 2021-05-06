#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height of a tree or 0
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i = 0, j = 0;

	if (!tree)
		return (0);
	i = binary_tree_height(tree->left) + 1;
	j = binary_tree_height(tree->right) + 1;
	if (i > j)
		return (i);
	else
		return (j);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: balance factor or 0
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int i = 0, j = 0;

	if (!tree)
		return (0);
	i = binary_tree_height(tree->left);
	j = binary_tree_height(tree->right);
	return (i - j);
}

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 * @root:  a double pointer to the root node of the Heap
 * @value: the value to store in the node to be inserted
 * Return: return a pointer to the inserted node, or NULL on failure
 **/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *bt;
}
