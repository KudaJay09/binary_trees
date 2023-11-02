#include "binary_trees.h"

/**
binary_tree_is_perfect - checks if a binary tree is perfect.
@tree: A pointer to the root node of the tree to check.
Return: If the tree is perfect - 1. else 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int left_depth, right_depth;

    if (tree == NULL)
        return (0);

    left_depth = binary_tree_height(tree->left);
    right_depth = binary_tree_height(tree->right);

    if (left_depth == right_depth)
        return (1 << left_depth) - 1;

    return (0);
}