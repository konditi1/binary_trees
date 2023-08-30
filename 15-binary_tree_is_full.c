#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if binary tree is full, otherwise 0
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_left_full, is_right_full;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
	{
		is_left_full = binary_tree_is_full(tree->left);
		is_right_full = binary_tree_is_full(tree->right);
		return (is_left_full && is_right_full);
	}
	return (0);
}
