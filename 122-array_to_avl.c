#include "binary_trees.h"

/**
avl_remove - removes a node from an AVL tree.
@root: A pointer to the root node of the tree for removing a node.
@value: The value to remove.
Return: 
*/
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            avl_t *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            avl_t *temp = minValueNode(root->right);

            root->n = temp->n;

            root->right = avl_remove(root->right, temp->n);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}