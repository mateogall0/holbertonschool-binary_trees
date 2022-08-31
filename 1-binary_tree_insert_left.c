#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts binary tree at left
 * @parent: parent of node
 * @value: data for node
 * Return: node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = 0;

	if (!parent)
		return (0);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (0);
	new->n = value;
	if (parent->left)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;
	new->parent = parent;
	return (new);
}
/**
 * _binary_tree_delete - frees a binary tree
 * @tree: root
 */
void _binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree->right)
		binary_tree_delete(tree->right);
	free(tree);
}
