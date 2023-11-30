#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right roatation on a binary tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: pointer to the root node of the tree once rotated
 *         NULL upon fialure
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pivot = tree->left;
	tree->left = pivot->right;
	if (pivot->right != NULL)
	{
		pivot->right->parent = tree;
	}
	pivot->right = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
