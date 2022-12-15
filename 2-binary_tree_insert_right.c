#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * Description: If parent already has a right-child, the NewNode node
 *              takes its place and the old right-child is set as
 *              the right-child of the NewNode.
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the NewNode.
 *
 * Return: If parent is NULL or failure occurs - NULL.
 *         else a pointer to the NewNode.
 *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *NewNode;

	if (parent == NULL)
		return (NULL);

	NewNode = binary_tree_node(parent, value);
	if (NewNode == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		NewNode->right = parent->right;
		parent->right->parent = NewNode;
	}
	parent->right = NewNode;

	return (NewNode);
}
