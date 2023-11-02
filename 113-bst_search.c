#include "binary_trees.h"

/**
bst_search - searches for a value in a Binary Search Tree.
@tree: A pointer to the root node of the BST.
@value: The value to search in the tree.
Return: If the tree is NULL or nothing is found - NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}