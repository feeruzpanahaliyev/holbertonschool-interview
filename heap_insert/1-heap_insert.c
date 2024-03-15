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
void heapify_up(heap_t **heap, heap_t *node)
{
    heap_t *parent = NULL;

    while (node && node->parent)
    {
        parent = node->parent;
        if (node->n > parent->n)
        {
            swap_nodes(&parent, &node);
            node = parent;
        }
        else
            break;
    }

    if (node && !node->parent && node->n > (*heap)->n)
        *heap = node;
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
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    parent = *root;
    while (parent->left && parent->right)
    {
        if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
            parent = parent->left;
        else
            parent = parent->right;
    }

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;
    heapify_up(root, new_node);

    return (new_node);
}
