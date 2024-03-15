#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap_nodes - Swaps two binary tree nodes
 * @parent: Pointer to the parent node
 * @child: Pointer to the child node
 */
void swap_nodes(heap_t **parent, heap_t **child)
{
    int temp = (*parent)->n;

    (*parent)->n = (*child)->n;
    (*child)->n = temp;
}

/**
 * heapify_up - Moves a node up the tree to maintain Max Heap property
 * @heap: Pointer to the heap
 * @node: Pointer to the inserted node
 */
void heapify(heap_t **root)
{
    heap_t *largest = *root;
    heap_t *left = (*root)->left;
    heap_t *right = (*root)->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != *root)
    {
        swap_nodes(*root, largest);
        heapify(&largest);
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node = binary_tree_node(*root, value);

    if (!node)
        return (NULL);

    /* Insert as a leaf */
    if (*root == NULL)
        *root = node;
    else
    {
        heap_t *parent = *root;
        while (1)
        {
            if (value > parent->n)
            {
                if (parent->left == NULL)
                {
                    parent->left = node;
                    break;
                }
                parent = parent->left;
            }
            else
            {
                if (parent->right == NULL)
                {
                    parent->right = node;
                    break;
                }
                parent = parent->right;
            }
        }
    }

    /* Maintain heap property */
    heapify(root);

    return (node);
}
