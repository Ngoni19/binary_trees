#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t Hl = 0, Hr = 0;

		Hl = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		Hr = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((Hl > Hr) ? Hl : Hr);
	}
	return (0);
}
