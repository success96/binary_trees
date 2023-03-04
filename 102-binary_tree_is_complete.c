#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete
 *         0 if tree is not complete
 *         0 if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	return (binary_tree_is_complete_helper(tree, 0, size));
}

/**
 * binary_tree_is_complete_helper - helper function for
 *                                  binary tree
 * @tree: pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in tree
 *
 * Return: 1 if tree is complete, or 0 for NULL or
 *         incomplete tree
 */
int binary_tree_is_complete_helper(const binary_tree_t *tree,
		size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_is_complete_helper(tree->left,
		2 * index + 1, size)
		&& binary_tree_is_complete_helper(tree->right,
		2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of tree, or 0 is tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}


