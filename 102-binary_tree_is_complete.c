#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if @tree is complete, otherwise 0
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_null_valid = 1;

	if (tree == NULL)
		return (0);

	return (is_complete(tree, &is_null_valid));
}

/**
 * is_complete - check if a tree is complete
 *
 * @tree: the tree
 * @is_null_valid: check if right node can be null
 *
 * Return: 1 if tree is complete, otherwise 0
 **/
int is_complete(const binary_tree_t *tree, int *is_null_valid)
{
	if (tree == NULL)
	{
		if (*is_null_valid)
		{
			*is_null_valid = 0;
			return (1);
		}

		return (0);
	}

	if (*is_null_valid == 0)
		return(0);

	if (tree->left == NULL)
	{
		if (tree->right == NULL)
			return (1);
		return (0);
	}

	return (is_complete(tree->left, is_null_valid) &&
			is_complete(tree->right, is_null_valid));
}
