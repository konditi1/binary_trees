#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node
 **/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	return (get_sibling(node->parent));
}

/**
 * get_sibling - finds the sibling of a node
 *
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node
 **/
binary_tree_t *get_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	return (node->parent->left == node ?
			node->parent->right :
			node->parent->left);
}
