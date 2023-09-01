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
	size_t height = get_height(tree);

	if (tree == NULL)
		return (0);

	return (is_complete(tree, &is_null_valid, height));
}

/**
 * is_complete - check if a tree is complete
 *
 * @tree: the tree
 * @is_null_valid: check if right node can be null
 * @height: the height of the tree
 *
 * Return: 1 if tree is complete, otherwise 0
 **/
int is_complete(const binary_tree_t *tree, int *is_null_valid, size_t height)
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
		return (0);

	if (tree->left == NULL)
	{
		if (tree->right == NULL)
		{
			if (get_depth(tree) == height ||
					get_depth(tree) + 1 == height)
			{
				if (get_depth(tree) < height)
					*is_null_valid = 0;
				return (1);
			}
		}
		return (0);
	}

	return (is_complete(tree->left, is_null_valid, height) &&
			is_complete(tree->right, is_null_valid, height));
}

/**
 * get_depth - measures the depth of a node in a binary tree
 *
 * @tree: a pointer to the node to measure the depth
 *
 * Return: the depth of a node
 **/
size_t get_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	return (get_depth(tree->parent) + 1);
}

/**
 * get_height - measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of a binary tree
 **/
size_t get_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	return ((left_height > right_height ? left_height  + 1 : right_height + 1));
}
