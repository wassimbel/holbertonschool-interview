#include "binary_trees.h"


/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of a tree or 0
 **/

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height of a tree or 0
 **/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t i = 0, j = 0;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);
	i = binary_tree_height(tree->left) + 1;
	j = binary_tree_height(tree->right) + 1;

	if (i > j)
		return (i);
	else
		return (j);
}

/**
 * binary_tree_preorder - function that goes through a binary tree
 * using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @root: double pointer to root
 * @height: height of tree
 **/

void binary_tree_preorder(heap_t *tree, heap_t **root, size_t height)
{
	if (!tree)
		return;
	if (!height)
		*root = tree;
	height--;
	binary_tree_preorder(tree->left, root, height);
	binary_tree_preorder(tree->right, root, height);
}




/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int i;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;
	tmp1 = root;
	while (1 == 1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		i = tmp1->n;

		tmp1->n = tmp2->n;
		tmp2->n = i;
		tmp1 = tmp2;
	}
}
/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: returns the value stored in the root node
 **/
int heap_extract(heap_t **root)
{
	int i;
	heap_t *heap, *node;

	if (!root || !*root)
		return (0);
	heap = *root;
	i = heap->n;
	if (!heap->left && !heap->right)
	{
		*root = NULL;
		free(heap);
		return (i);
	}

	binary_tree_preorder(heap, &node, binary_tree_height(heap));

	heap->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap);
	*root = heap;
	return (i);
}
