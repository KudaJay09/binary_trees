#include "binary_trees.h"

/**
binary_tree_is_complete - checks if a binary tree is complete.
@tree: A pointer to the root node of the tree to check.
Return: If tree is NULL - 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
    queue_t *queue = NULL;
    const binary_tree_t *node = NULL;
    int flag = 0;

    if (!tree)
        return (0);

    queue = queue_create();
    if (!queue)
        return (0);

    queue_push(queue, (void *)tree);
    while (queue_size(queue))
    {
        node = (const binary_tree_t *)queue_pop(queue);
        if (!node)
            flag = 1;
        else
        {
            if (flag)
            {
                queue_delete(queue);
                return (0);
            }
            queue_push(queue, (void *)node->left);
            queue_push(queue, (void *)node->right);
        }
    }

    queue_delete(queue);
    return (1);
}
