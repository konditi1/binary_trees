#include "binary_trees.h"


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree
 * to measure the balance factor
 *
 * Return: the balance factor of a binary tree
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (b_tree_height(tree->left) - b_tree_height(tree->right));
}

/**
 * b_tree_height - measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of a binary tree
 **/
int b_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = b_tree_height(tree->left);
	right_height = b_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
