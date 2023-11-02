#include "binary_trees.h"

/**
avl_insert - inserts a value in an AVL Tree.
@tree: A double pointer to the root node of the AVL tree for inserting the value.
@value: the value to store in the node to be inserted.
Return: Pointer to the created node, or NULL on failure
*/
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    if (!tree)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*tree)
        return (*tree = new_node);

    if (value < (*tree)->n)
        (*tree)->left = avl_insert(&(*tree)->left, value);
    else if (value > (*tree)->n)
        (*tree)->right = avl_insert(&(*tree)->right, value);
    else
        return (free(new_node), NULL);

    return (balance_avl(tree));
}