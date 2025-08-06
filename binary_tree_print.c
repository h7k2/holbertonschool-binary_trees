#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_tree - recursively prints a binary tree
 * @tree: pointer to the root node
 * @offset: offset for printing
 * @depth: current depth
 * @buffer: the print buffer
 * Return: new offset
 */
static int print_tree(const binary_tree_t *tree, int offset, int depth, char **buffer)
{
	char b[6];
	int width = 5;
	int left, right, is_left, i;

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
 * binary_tree_print - prints a binary tree
 * @tree: pointer to the root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **buffer;
	int height, i, j;

	if (!tree)
		return;

	height = 1000;
	buffer = malloc(sizeof(*buffer) * height);
	if (!buffer)
		return;

	for (i = 0; i < height; i++)
	{
		buffer[i] = malloc(sizeof(**buffer) * 255);
		if (!buffer[i])
			return;
		memset(buffer[i], ' ', 255 - 1);
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
