#include "binary_trees.h"

unsigned char n_is_leaf(const binary_tree_t *node);
size_t bt_depth(const binary_tree_t *tree);
const binary_tree_t *get_lf(const binary_tree_t *tree);
int is_perfect_recur(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * n_is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: pointer to the node to check.
 *
 * Return: If the node is a leaf -> 1, else -> 0.
 */
unsigned char n_is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * bt_depth - Returns the bt_depth of a given
 *         node in a binary tree.
 * @tree: pointer to the node to measure the bt_depth.
 *
 * Return: bt_depth of node.
 */
size_t bt_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + bt_depth(tree->parent) : 0);
}

/**
 * get_lf - Returns a leaf of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: pointer to the first encountered leaf.
 */
const binary_tree_t *get_lf(const binary_tree_t *tree)
{
	if (n_is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_lf(tree->left) : get_lf(tree->right));
}

/**
 * is_perfect_recur - Checks if a bt is perfct recursively.
 * @tree: pointer to the root node of the tree.
 * @leaf_depth: bt_depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect -> 1, else ->  0.
 */
int is_perfect_recur(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (n_is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recur(tree->left, leaf_depth, level + 1) &&
		is_perfect_recur(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect -> Checks if a bt is perfect.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect -> 0.
 *         else -> 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recur(tree, bt_depth(get_lf(tree)), 0));
}
