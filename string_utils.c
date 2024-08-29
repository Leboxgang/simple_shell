#include "shell.h"

/* _strncpy: Copies a string up to a specified number of characters
 * @dest: Destination buffer for the copied string
 * @src: Source string to copy from
 * @n: Maximum number of characters to copy
 * Return: Pointer to the resulting string (dest)
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/* _strncat: Concatenates two strings up to a specified number of bytes
 * @dest: The first string, and the destination for concatenation
 * @src: The second string to append to dest
 * @n: Maximum number of bytes to concatenate from src
 * Return: Pointer to the resulting string (dest)
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/* _strchr: Finds the first occurrence of a character in a string
 * @s: The string to search through
 * @c: The character to find
 * Return: Pointer to the first occurrence of the character in s, or NULL
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
