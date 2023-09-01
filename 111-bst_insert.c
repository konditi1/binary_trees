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
			else if (!insert(temp, new_node, value))
			{
				free(new_node);
				return (NULL);
			}
			else
				break;
		}
	}
	return (new_node);
}

/**
 * insert - helper function to insert a node in bst
 *
 * @temp: the subtree
 * @new_node: the new node
 * @value: the value to insert
 *
 * Return: 1 if insertion was successfull, otherwise 0
 **/
int insert(bst_t *temp, bst_t *new_node, int value)
{
	if (temp->n > value && temp->left == NULL)
		temp->left = new_node;
	else if (temp->n < value && temp->right == NULL)
		temp->right = new_node;
	else if (temp->n == value)
		return (0);

	return (1);
}
