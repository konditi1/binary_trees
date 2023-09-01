#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary
 * tree using level-order traversal
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = get_height(tree);

	for (level = 0; level < height; level++)
		traverse_levelorder(tree, level, func);
}

/**
 * traverse_levelorder - traverse through a binary
 * tree using level order traversal
 *
 * @root: a pointer to the root node
 * @level: the level to print its items
 * @func: the function to call for each node
 **/
void traverse_levelorder(binary_tree_t const *root,
		size_t level, void (*func)(int))
{
	if (root == NULL)
		return;

	if (level == 0)
		func(root->n);
	else
	{
		traverse_levelorder(root->left, level - 1, func);
		traverse_levelorder(root->right, level - 1, func);
	}
}

/**
 * get_height - get the height of a tree
 *
 * @tree: a pointer to the root node of the tree
 *
 * Return: the height of the tree
 **/
size_t get_height(binary_tree_t const *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
