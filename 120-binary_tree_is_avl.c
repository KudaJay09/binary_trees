#include "binary_tree.h"

/**
binary_tree_is_avl - checks if a binary tree is a valid.
@tree: A pointer to the root of the tree to check.
Return: If trr is a valid AVL Tree - 1. otherwise 0
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height_left, height_right;

    if (!tree)
        return (0);

    height_left = binary_tree_height(tree->left);
    height_right = binary_tree_height(tree->right);

    if (abs(height_left - height_right) > 1)
        return (0);

    if (tree->left && !binary_tree_is_avl(tree->left))
        return (0);

    if (tree->right && !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}