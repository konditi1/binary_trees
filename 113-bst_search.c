#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing a value equals to value
 **/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp = (bst_t *)tree;

	if (temp == NULL)
		return (NULL);

	while (temp != NULL)
	{
		if (temp->n == value)
			return (temp);

		temp = temp->n > value ? temp->left : temp->right;
	}

	return (NULL);
}
