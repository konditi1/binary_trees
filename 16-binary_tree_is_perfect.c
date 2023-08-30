#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if a binary tree is perfect, otherwise 0
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth = 0;

	return (is_perfect(tree, &depth));
}

/**
 * is_perfect - check if binary tree is perfect
 *
 * @tree: the tree to check
 * @depth: a pointer to the depth of a node
 *
 * Return: 1 if tree is perfect, otherwise 0
 **/
int  is_perfect(const binary_tree_t *tree, size_t *depth)
{
	if (tree == NULL)
		return (0);

	if (is_leaf(tree))
	{
		if (*depth == 0)
			*depth = get_depth(tree);

		if (*depth == get_depth(tree))
			return (1);

		return (0);
	}

	return (is_perfect(tree->left, depth)
			&& is_perfect(tree->right, depth));
}

/**
 * is_leaf - check if a node in a binary tree is a leaf
 *
 * @tree: the node to be checked
 *
 * Return: 1 if the node is a leaf, otherwise 0
 **/
int is_leaf(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (0);
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
