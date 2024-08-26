#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include"main.h"


/**
 * main- function that prints to the shell
 *
 * Return: 0 always
 */

int main(void)
{
	char *command = NULL;
	size_t len_command = 0;
	int status;
	int line;

	while (1)
	{
		printf("$ ");

		line = getline(&command, &len_command, stdin);


		if (line == -1)
		{
			free(command);
			printf("The program to read the command failed\n");
			return (1);
		}
		else
		{
			create_process(command);
			wait(&status);
		}
		free(command);
		command = NULL;
	}
	free(command);
	return (0);
}
