#include "shell.h"

/**
 * bfree: Frees a dynamically allocated pointer and sets it to NULL
 * @ptr: Address of the pointer to be freed
 *
 * Return: 1 if memory was successfully freed, otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
