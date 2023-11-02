#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 * Return: If an error occurs or if parent is NULL - NULL. Otherwise - a pointer to the created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *temp;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;

	if (parent->left == NULL)
	{
		parent->left = new;
		new->left = NULL;
	}
	else
	{
		temp = parent->left;
		parent->left = new;
		new->left = temp;
		temp->parent = new;
	}

	return (new);
}