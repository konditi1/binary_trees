#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root:  a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 **/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = root, *successor;

	if (root == NULL)
		return (NULL);

	while (temp != NULL)
	{
		if (value == temp->n)
		{
			if (temp->left != NULL && temp->right != NULL)
			{
				successor = get_successor(temp->right);
				if (temp->right != successor)
				{
					successor->parent->left = NULL;
					successor->right = temp->right;
				}
				successor->parent = temp->parent;
				successor->left = temp->left;

				if (temp->parent == NULL)
					root = successor;
			}
			else if (temp->left == NULL && temp->parent == NULL)
				root = temp->right;
			else if (temp->right == NULL && temp->parent == NULL)
				root = temp->left;

			free(temp);
			return(root);
		}

		temp = temp->n > value ? temp->left : temp->right;
	}

	return (NULL);
}

/**
 * get_successor - get the successor of node
 *
 * @node: the node
 *
 * Return: the successor of @node
 **/
bst_t *get_successor(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->left == NULL)
		return (node);

	return (get_successor(node->left));
}
