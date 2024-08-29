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
	return (0);
}
