#include"shell.h"

/**
 * shell_loop - primary loop for the shell's execution
 * @info: the struct containing parameters and return information
 * @av: argument vector from the main function
 *
 * Return: 0 on success, 1 on error, or an error code
 */
int shell_loop(info_t *info, char **av)
{
	ssize_t input_status = 0;
	int builtin_result = 0;

	while (input_status != -1 && builtin_result != -2)
	{
		clear_info(info);
		if (is_interactive(info))
			print_prompt("$ ");
		flush_buffer();
		input_status = get_input(info);
		if (input_status != -1)
		{
			populate_info(info, av);
			builtin_result = execute_builtin(info);
			if (builtin_result == -1)
				execute_command(info);
		}
		else if (is_interactive(info))
			write_char('\n');
		release_info(info, 0);
	}
	write_history(info);
	release_info(info, 1);
	if (!is_interactive(info) && info->status)
		exit(info->status);
	if (builtin_result == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_result);
}

/**
 * execute_builtin - searches for and executes a builtin command
 * @info: the struct containing parameters and return information
 *
 * Return: -1 if the builtin is not found,
 *          0 if the builtin executes successfully,
 *          1 if the builtin is found but fails,
 *          -2 if the builtin triggers an exit()
 */
int execute_builtin(info_t *info)
{
	int i, result = -1;
	builtin_table builtins[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{"help", shell_help},
		{"history", shell_history},
		{"setenv", shell_setenv},
		{"unsetenv", _unsetenv},
		{"cd", shell_cd},
		{"alias", shell_alias},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].type; i++)
		if (compare_strings(info->argv[0], builtins[i].type) == 0)
		{
			info->line_count++;
			result = builtins[i].func(info);
			break;
		}
	return (result);
}

/**
 * execute_command - locates a command in the PATH and executes it
 * @info: the struct containing parameters and return information
 *
 * Return: void
 */
void execute_command(info_t *info)
{
	char *command_path = NULL;
	int i, cmd_len;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, cmd_len = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			cmd_len++;
	if (!cmd_len)
		return;

	command_path = locate_path(info, get_env_var(info, "PATH="), info->argv[0]);
	if (command_path)
	{
		info->path = command_path;
		run_command(info);
	}
	else
	{
		if ((is_interactive(info) || get_env_var(info, "PATH=")
			|| info->argv[0][0] == '/') && is_executable(info, info->argv[0]))
			run_command(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error_message(info, "Command not found\n");
		}
	}
}

/**
 * run_command - creates a child process to execute the command
 * @info: the struct containing parameters and return information
 *
 * Return: void
 */
void run_command(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execute_program(info->path, info->argv, getenv(info)) == -1)
		{
			release_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error_message(info, "Permission denied\n");
		}
	}
}
