#include"main.h"

/**
 * **string_tokens - tokenize strings
 * @str: The string to be tokenized
 * @delimiter: The delimeters of the string
 *
 * Return: Return the tokenized strings
 */

char **string_tokens(char *str, char *delimiter)
{
	int len = 1;
	char **tokens;
	char *token;
	int index;

	tokens = malloc(len * sizeof(char *));
	token = strtok(str, delimiter);
	while (token != NULL)
	{
		index = len - 1;
		len++;
		tokens = realloc(tokens, len * sizeof(char *));
		tokens[index] = malloc(strlen(token) * sizeof(char));
		strcpy(tokens[index], token);
		token = strtok(NULL, delimiter);
	}

	tokens[len - 1] = NULL;

	return (tokens);

}
