#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lef = 0, rig = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lef = (1 + binary_tree_height(tree->left));
	if (tree->right)
		rig = (1 + binary_tree_height(tree->right));
	return (lef > rig ? lef : rig);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *        the balance factor
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	left = tree->left ? (int)binary_tree_height(tree->left) : -1;
	right = tree->right ? (int)binary_tree_height(tree->right) : -1;
	return (left - right);
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_balance(tree) != 0)
		return (0);
	if (!tree->right && !tree->left)
		return (1);
	if (tree->right && tree->left)
	{
		return (binary_tree_is_perfect(tree->right) &&
			binary_tree_is_perfect(tree->left));
	}
	return (0);
}
