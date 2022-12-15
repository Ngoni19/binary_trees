#include "binary_trees.h"

/**
 * binary_tree_size -> Measures the _size of a binary tree.
 * @tree: pointer to the root node of the tree to measure the _size of.
 *
 * Return: _size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t _size = 0;

	if (tree)
	{
		_size += 1;
		_size += binary_tree_size(tree->left);
		_size += binary_tree_size(tree->right);
	}
	return (_size);
}
