#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node ina binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}

/**
 * binary_tree_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 *         If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (binary_tree_depth(first) > binary_tree_depth(second))
		return (binary_trees_ancestor(first->parent, second));
	if (binary_tree_depth(first) < binary_tree_depth(second))
		return (binary_trees_ancestor(first, second->parent));
	if (binary_tree_depth(first) == binary_tree_depth(second))
		return (binary_trees_ancestor(first->parent, second->parent));
	return (NULL);
}
