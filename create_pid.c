#include"main.h"

/**
 * create_process - create a new process ID
 * @str: A string of characters as parameter
 *
 * Return: Return an integer
 */

int create_process(char *str)
{
	pid_t my_pid;


	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error");
		return (0);
	}
	if (my_pid == 0)
	{
		char **argv = string_tokens(str, " \t\n");

		print_tokens(argv);

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}

		return (0);
}
