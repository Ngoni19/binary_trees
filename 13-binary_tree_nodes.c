#include "binary_trees.h"

/**
 * binary_tree_nodes -> Counts Nodes with at least 1 child in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of Nodes.
 *
 * Return: If tree is NULL, function return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t Nodes = 0;

	if (tree)
	{
		Nodes += (tree->left || tree->right) ? 1 : 0;
		Nodes += binary_tree_nodes(tree->left);
		Nodes += binary_tree_nodes(tree->right);
	}
	return (Nodes);
}
