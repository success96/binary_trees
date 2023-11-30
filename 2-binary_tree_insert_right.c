#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 * @parent: pointer to node to insert right child
 * @value: value to store in new node
 *
 * Return: pointer to created node or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	node->right = parent->right;
	parent->right = node;

	if (node->right)
		node->right->parent = node;

	return (node);

}
