#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_insert_left -inserts a node as the
 * left-child of another node
 * Description: If parent already has a left-child, the NewNode node
 *              takes its place and the old left-child is set as
 *              the left-child of the NewNode node.
 * @parent: pointer to the node to insert in the left-child.
 * @value: value to store in the NewNode node.
 *
 * Return: If parent is NULL or an failure occurs -> NULL.
 *         else pointer to the NewNode node.
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *NewNode;

	if (parent == NULL)
		return (NULL);

	NewNode = binary_tree_node(parent, value);
	if (NewNode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		NewNode->left = parent->left;
		parent->left->parent = NewNode;
	}
	parent->left = NewNode;

	return (NewNode);
}
