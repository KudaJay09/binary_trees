#include "binary_trees.h"

/**
binary_tree_is_full - measures the balance factor of a binary tree.
@tree: A pointer to the root of the tree to measure balance factor
Return: The balance factor of the binary tree.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height - right_height);
}