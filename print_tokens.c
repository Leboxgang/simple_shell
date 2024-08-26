#include"main.h"

void print_tokens(char **tokens)
{
	int i =0;
	while (tokens[i] != NULL)
		printf("%s\n", tokens[i++]);
}
