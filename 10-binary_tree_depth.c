#include "binary_trees.h"

/**
binary_tree_depth - measures the depth of a node in a binary tree.
@tree: A pointer to node to measure depth.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    size_t left_depth = binary_tree_depth(tree->left);
    size_t right_depth = binary_tree_depth(tree->right);
    return (1 + (left_depth > right_depth ? left_depth : right_depth));
}