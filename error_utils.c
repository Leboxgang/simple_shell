#include "shell.h"

/* _erratoi: Converts a string into an integer
 * @s: Input string to convert
 * Return: Returns 0 if no digits are found, or the converted number. 
 *         Returns -1 if an error occurs.
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/* print_error: Outputs an error message
 * @info: Struct containing parameters and return info
 * @estr: String with the error message
 * Return: None
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/* print_d: Outputs a decimal number (base 10)
 * @input: The number to print
 * @fd: The file descriptor for output
 *
 * Return: Number of characters output
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int abs_val, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		abs_val = -input;
		__putchar('-');
		count++;
	}
	else
		abs_val = input;
	current = abs_val;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs_val / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/* convert_number: Converts a number to a string based on the given base
 * @num: Number to convert
 * @base: Base for conversion
 * @flags: Flags to modify behavior
 *
 * Return: Pointer to the resulting string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/* remove_comments: Removes comments from a string by replacing '#' with '\0'
 * @buf: Pointer to the string to modify
 *
 * Return: None
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
