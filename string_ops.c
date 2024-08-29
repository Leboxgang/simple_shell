#include "shell.h"

/**
 * copy_string - Copies the content of one string to another.
 * @dest: The destination buffer.
 * @src: The source string to copy.
 *
 * Return: Pointer to the destination buffer.
 */
char *copy_string(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * duplicate_string - Creates a duplicate of the given string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string, or NULL on failure.
 */
char *duplicate_string(const char *str)
{
	int length = 0;
	char *copy;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	copy = malloc(sizeof(char) * (length + 1));
	if (!copy)
		return (NULL);
	for (length++; length--;)
		copy[length] = *--str;
	return (copy);
}
int output_char(char c);
/**
 * print_string - Outputs a string to the standard output.
 * @str: The string to be printed.
 *
 * Return: None.
 */
void print_string(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		output_char(str[i]);
		i++;
	}
}

/**
 * output_char - Writes a single character to the standard output.
 * @c: The character to print.
 *
 * Return: On success 1, on error -1 with errno set appropriately.
 */
int output_char(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}
