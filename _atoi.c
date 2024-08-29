#include "shell.h"

/**
 * interactive - checks if shell is in interactive mode
 * @info: pointer to struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd < 3);
}

/**
 * is_delim - determines if a character is a delimiter
 * @c: the character to evaluate
 * @delim: the string containing delimiters
 * Return: 1 if true, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - verifies if character is alphabetic
 * @c: the character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - transforms a string into an integer
 * @s: the input string
 * Return: 0 if no digits in string, else the converted number
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, flag = 0;
	unsigned int result = 0;

	for (; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	return (sign == -1) ? -(int)result : (int)result; /* Simplified return statement */
}
