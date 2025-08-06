#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_tree - Recursively stores a visual representation of the tree
 * @tree: Pointer to the node
 * @offset: Horizontal offset
 * @depth: Current depth level
 * @buffer: 2D array for storing characters
 *
 * Return: Total offset used
 */
static int print_tree(const binary_tree_t *tree, int offset, int depth, char **buffer)
{
	char b[6];
	int width = 5;
	int left, is_left, i;

	if (!tree)
		return (0);

	is_left = (tree->parent && tree->parent->left == tree);
	offset += print_tree(tree->right, offset, depth + 1, buffer);

	sprintf(b, "(%03d)", tree->n);
	for (i = 0; i < width && b[i]; i++)
		buffer[depth][offset + i] = b[i];

	if (depth && is_left)
	{
		for (i = 0; i < width + 1; i++)
			buffer[depth - 1][offset + width / 2 - i] = '-';
		buffer[depth - 1][offset + width / 2 + 1] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < width + 1; i++)
			buffer[depth - 1][offset - width / 2 + i] = '-';
		buffer[depth - 1][offset - width / 2 - 1] = '.';
	}

	left = print_tree(tree->left, offset + width, depth + 1, buffer);
	return (offset + width + left);
}

/**
 * binary_tree_print - Prints a binary tree visually
 * @tree: Pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **buffer;
	int height = 1000, i, j;

	if (!tree)
		return;

	buffer = malloc(sizeof(*buffer) * height);
	if (!buffer)
		return;

	for (i = 0; i < height; i++)
	{
		buffer[i] = malloc(sizeof(**buffer) * 255);
		if (!buffer[i])
			return;
		memset(buffer[i], ' ', 254);
		buffer[i][254] = '\0';
	}

	print_tree(tree, 0, 0, buffer);

	for (i = 0; i < height && buffer[i][0] != ' '; i++)
	{
		for (j = 254 - 1; j > 0; j--)
		{
			if (buffer[i][j] != ' ')
				break;
			buffer[i][j] = '\0';
		}
		printf("%s\n", buffer[i]);
		free(buffer[i]);
	}
	free(buffer);
}

