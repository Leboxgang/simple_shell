#include "shell.h"

/**
 * display_env: prints current environment variables
 * 
 * Return: Always 0
 */
int display_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * fetch_env_value: retrieves the value of an environment variable
 * @name: the name of the environment variable
 *
 * Return: the value of the environment variable or NULL if not found
 */
char *fetch_env_value(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *value;

	while (node)
	{
		value = starts_with(node->str, name);
		if (value && *value)
			return (value);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_env_var: adds or updates an environment variable
 * 
 * Return: 0 on success, 1 on failure
 */
int set_env_var(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_env_var: removes an environment variable
 *
 * Return: Always 0
 */
int unset_env_var(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * initialize_env_list: initializes the environment variable linked list
 * 
 * Return: Always 0
 */
int initialize_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
