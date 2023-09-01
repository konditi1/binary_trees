#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 **/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *temp;

	temp = *tree;
	new_node = malloc(sizeof(bst_t));
	if (new_node == NULL)
		return (NULL);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;
	if (*tree == NULL)
	{
		new_node->parent = NULL;
		*tree = new_node;
	}
	else
	{
		while (temp != NULL)
		{
			new_node->parent = temp;

			if ((temp->n > value && temp->left != NULL) ||
					(temp->n < value && temp->right != NULL))
				temp = temp->n > value ? temp->left : temp->right;
			else if ((temp->n > value && temp->left == NULL) ||
					(temp->n < value && temp->right == NULL) ||
					(temp->n == value))
			{
				if (temp->n > value && temp->left == NULL)
					temp->left = new_node;
				else if (temp->n < value && temp->right == NULL)
					temp->right = new_node;
				else if (temp->n == value)
					free(new_node);
				break;
			}
		}
	}
	return (new_node);
}
