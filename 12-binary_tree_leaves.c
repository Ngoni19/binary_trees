#include "binary_trees.h"

/**
 * binary_tree_leave -> Counts the _leaves in a binary tree.
 * @tree: pointer to the root node of the tree to count the _leaves.
 *
 * Return: number of _leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t _leaves = 0;

	if (tree)
	{
		_leaves += (!tree->left && !tree->right) ? 1 : 0;
		_leaves += binary_tree_leaves(tree->left);
		_leaves += binary_tree_leaves(tree->right);
	}
	return (_leaves);
}
