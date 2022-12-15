#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the NewNode node.
 *
 * Return: NULL if error occurs.
 *         thus pointer to the NewNode node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *NewNode;

	NewNode = malloc(sizeof(binary_tree_t));
	if (NewNode == NULL)
		return (NULL);

	NewNode->n = value;
	NewNode->parent = parent;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return (NewNode);
}
