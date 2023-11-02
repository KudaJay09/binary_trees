#include "binary_trees.h"

/**
binary_tree_ancestor - 
@first: A pointer to first node.
@second: A pointer to second node.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return (NULL);

    if (first == second)
        return ((binary_tree_t *)first);

    if (first == second->parent)
        return ((binary_tree_t *)second);

    if (second == first->parent)
        return ((binary_tree_t *)first);

    if (first->parent == second->parent)
        return (binary_trees_ancestor(first->parent, first));

    return (binary_trees_ancestor(first->parent, second->parent));
}
