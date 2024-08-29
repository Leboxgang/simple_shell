#include "shell.h"

/* _eputs: Outputs a string to stderr
 * @str: String to output
 *
 * Return: None
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/* _eputchar: Sends a character to stderr
 * @c: Character to output
 *
 * Return: 1 if successful, -1 on failure, setting errno
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/* _putfd: Outputs a character to a specific file descriptor
 * @c: Character to output
 * @fd: File descriptor to write to
 *
 * Return: 1 if successful, -1 on failure, setting errno
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/* _putsfd: Outputs a string to a specified file descriptor
 * @str: String to output
 * @fd: File descriptor to write to
 *
 * Return: Number of characters output
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
