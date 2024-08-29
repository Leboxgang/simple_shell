<<<<<<< HEAD
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char *program_name = "simple shell";
	char *args[2];

	while (1)
	{
		printf("simple shell$ ");
		nread = getline(&buffer, &bufsize, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				free(buffer);
				exit(0);
			}
			else
			{
				perror("getline");
				free(buffer);
				exit(1);
			}
		}

		buffer[strcspn(buffer, "\n")] = 0;
		
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}

		args[0] = buffer;
		args[1] = NULL;
		
		if (fork() == 0)
		{
			if (execve(buffer, args, NULL) == -1)
			{
				perror(program_name);
				exit(errno);
			}
		}
		else
		{
			wait(NULL);
		}
	}

	free(buffer);
=======
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
>>>>>>> ce3e7f1fdad37ea723ae0329b63272de77ccc456
	return (0);
}
