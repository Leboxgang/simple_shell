#include "shell.h"

/**
 * exit_shell: exits shell program
 * Pointer to structure
 * Return: (0) if info.argv[0] != "exit"
 */
int exit_shell(info_t *info)
{
	int exit_status;

	if (info->argv[1])
	{
		exit_status = _erratoi(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Error: Invalid number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_status;
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * change_directory
 * 
 * Return: Always 0
 */
int change_directory(info_t *info)
{
	char *current_dir, *new_dir, path_buf[1024];
	int cd_result;

	current_dir = getcwd(path_buf, 1024);
	if (!current_dir)
		_puts("Error: Unable to fetch current directory\n");
	if (!info->argv[1])
	{
		new_dir = _getenv(info, "HOME=");
		if (!new_dir)
			cd_result =
				chdir((new_dir = _getenv(info, "PWD=")) ? new_dir : "/");
		else
			cd_result = chdir(new_dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd_result = chdir((new_dir = _getenv(info, "OLDPWD=")) ? new_dir : "/");
	}
	else
		cd_result = chdir(info->argv[1]);
	if (cd_result == -1)
	{
		print_error(info, "Unable to change directory to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(path_buf, 1024));
	}
	return (0);
}

/**
 * provides help information
 * 
 * Return: Always 0
 */
int display_help(info_t *info)
{
	char **arg_list;

	arg_list = info->argv;
	_puts("Help functionality activated. Yet to be implemented.\n");
	if (0)
		_puts(*arg_list);
	return (0);
}
