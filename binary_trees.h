#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* print function */
void binary_tree_print(const binary_tree_t *tree);

/* binary tree node func */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* binary tree insert left func */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* binary tree insert right func */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* binary tree delete func */
void binary_tree_delete(binary_tree_t *tree);

/* binary tree is leaf func */
int binary_tree_is_leaf(const binary_tree_t *node);

/* binary tree is root func */
int binary_tree_is_root(const binary_tree_t *node);

/* binary tree preorder func */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* binary tree inorder func */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* binary tree postorder func */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* binary tree height func */
size_t binary_tree_height(const binary_tree_t *tree);

/* binary tree depth func */
size_t binary_tree_depth(const binary_tree_t *tree);

/* binary tree size func */
size_t binary_tree_size(const binary_tree_t *tree);

/* binary tree leaves func */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* binary tree nodes func */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* binary tree balance func */
int binary_tree_balance(const binary_tree_t *tree);

/* binary tree is full func */
int binary_tree_is_full(const binary_tree_t *tree);

/* binary tree is perfect func */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* binary tree sibling func */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* binary tree uncle func */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* binary trees ancestors func */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second);

/* binary tree levelorder func */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* binary tree is complete func */
int binary_tree_is_complete(const binary_tree_t *tree);

/* binary tree rotate left function */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* binary tree rotate right function */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* binary tree is bst function */
int binary_tree_is_bst(const binary_tree_t *tree);

/* binary tree bst insert function */
bst_t *bst_insert(bst_t **tree, int value);

/* array to bst function */
bst_t *array_to_bst(int *array, size_t size);

/* bst search function */
bst_t *bst_search(const bst_t *tree, int value);

/* bst remove function */
bst_t *bst_remove(bst_t *root, int value);

/* binary tree is avl function */
int binary_tree_is_avl(const binary_tree_t *tree);

/* avl insert function */
avl_t *avl_insert(avl_t **tree, int value);

/* array to avl function */
avl_t *array_to_avl(int *array, size_t size);

/* avl remove function */
avl_t *avl_remove(avl_t *root, int value);

/* sorted array to avl func */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* heap insert func */
heap_t *heap_insert(heap_t **root, int value);

/* array to heap func */
heap_t *array_to_heap(int *array, size_t size);

/* heap extract func */
int heap_extract(heap_t **root);

/* heap to sorted array */
int *heap_to_sorted_array(heap_t *heap, size_t *size);

/* helper functions */
void binary_tree_levelorder_helper(const binary_tree_t *tree,
				void (*func)(int), size_t level);
int binary_tree_is_complete_helper(const binary_tree_t *tree,
					size_t index, size_t size);
int binary_tree_is_bst_helper(const binary_tree_t *tree, int min, int max);
int binary_tree_is_avl_helper(const binary_tree_t *tree, int min, int max);
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval);
void bal(avl_t **tree);
int successor(bst_t *node);
int remove_type(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);
int binary_tree_is_heap(const binary_tree_t *tree);
int btih_helper(const binary_tree_t *tree);
void recurse_extract(heap_t *tree);
heap_t *last_node_heap(const heap_t *tree, size_t level);
size_t heap_tree_size(const binary_tree_t *tree);
#endif /* _BINARY_TREES_H_ */

