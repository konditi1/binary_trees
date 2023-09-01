#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 **/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_value = 0, prev_value_is_set = 0;

	if (tree == NULL)
		return (0);

	return (is_bst(tree, &prev_value, &prev_value_is_set));
}

/**
 * is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * @prev_value: the previous value to compare to
 * @prev_value_is_set: to check is prev_value is initialized
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 **/
int is_bst(const binary_tree_t *tree, int *prev_value, int *prev_value_is_set)
{
	int is_valid = 0;
	int check_dup = 1;

	if (tree == NULL)
		return (1);

	is_valid = is_bst(tree->left, prev_value, prev_value_is_set);

	if (!(*prev_value_is_set))
	{
		*prev_value = tree->n;
		*prev_value_is_set = 1;
		check_dup = 0;
	}

	if (!is_valid || *prev_value > tree->n ||
			(check_dup && *prev_value == tree->n))
		return (0);

	*prev_value = tree->n;
	return (is_bst(tree->right, prev_value, prev_value_is_set));
}
