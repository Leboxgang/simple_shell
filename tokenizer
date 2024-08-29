#include "shell.h"

/**
 * strtow - Splits a string into an array of words, ignoring repeated delimiters.
 * @str: The input string to be split.
 * @d: The string containing delimiter characters.
 * 
 * Return: Pointer to an array of strings (words), or NULL if splitting fails.
 */
char **strtow(char *str, char *d)
{
	int i, j, k, m, word_count = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || str[i + 1] == '\0'))
			word_count++;

	if (word_count == 0)
		return (NULL);
	words = malloc((1 + word_count) * sizeof(char *));
	if (!words)
		return (NULL);
	for (i = 0, j = 0; j < word_count; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = '\0';
	}
	words[j] = NULL;
	return (words);
}

/**
 * strtow2 - Splits a string into words using a single character delimiter.
 * @str: The input string to be split.
 * @d: The delimiter character.
 * 
 * Return: Pointer to an array of words, or NULL if splitting fails.
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, word_count = 0;
	char **words;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			word_count++;
	if (word_count == 0)
		return (NULL);
	words = malloc((1 + word_count) * sizeof(char *));
	if (!words)
		return (NULL);
	for (i = 0, j = 0; j < word_count; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		words[j] = malloc((k + 1) * sizeof(char));
		if (!words[j])
		{
			for (k = 0; k < j; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			words[j][m] = str[i++];
		words[j][m] = '\0';
	}
	words[j] = NULL;
	return (words);
}
