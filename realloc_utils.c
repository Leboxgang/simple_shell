#include "shell.h"

/**
 * _memset - Initializes a memory block with a specified byte.
 * 
 * Return: Pointer to the memory area `s`.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - Releases a null-terminated array of strings.
 * 
 */
void ffree(char **pp)
{
	char **temp = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(temp);
}

/**
 * _realloc - Resizes a previously allocated memory block.
 * 
 * Return: Pointer to the newly resized memory block, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_block;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	new_block = malloc(new_size);
	if (!new_block)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_block[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (new_block);
}
