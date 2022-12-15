#include "binary_trees.h"

/**
 * binary_trees_ancestor -> inds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mum, *papa;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mum = first->parent, papa = second->parent;
	if (first == papa || !mum || (!mum->parent && papa))
		return (binary_trees_ancestor(first, papa));
	else if (mum == second || !papa || (!papa->parent && mum))
		return (binary_trees_ancestor(mum, second));
	return (binary_trees_ancestor(mum, papa));
}
