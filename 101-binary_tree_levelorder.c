#include "binary_trees.h"

/**
binary_tree_levelorder - goes through a binary tree using levelorder traversal
@tree: A pointer to the root node of the tree to traverse.
@func: A pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    queue_t *queue = NULL;
    const binary_tree_t *node = NULL;

    if (!tree || !func)
        return;

    queue_push(&queue, (void *)tree);

    while (queue)
    {
        node = (const binary_tree_t *)queue_pop(&queue);
        func(node->n);

        if (node->left)
            queue_push(&queue, (void *)node->left);

        if (node->right)
            queue_push(&queue, (void *)node->right);
    }
}