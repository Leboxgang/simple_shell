#include "shell.h"

/**
 * displays history: lists all history entries with line numbers starting from 0.
 * 
 * Return: Always 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * remove alias
 * @str: alias string to remove
 *
 * Return: 0 if successful, 1 if failed
 */
int remove_alias(info_t *info, char *str)
{
	char *equal_pos, temp_char;
	int result;

	equal_pos = _strchr(str, '=');
	if (!equal_pos)
		return (1);
	temp_char = *equal_pos;
	*equal_pos = 0;
	result = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*equal_pos = temp_char;
	return (result);
}

/**
 * add alias: creates or updates an alias entry
 *
 * Return: 0 if successful, 1 if failed
 */
int add_alias(info_t *info, char *str)
{
	char *equal_pos;
	
	equal_pos = _strchr(str, '=');
	if (!equal_pos)
		return (1);
	if (!*++equal_pos)
		return (remove_alias(info, str));

	remove_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * display_alias
 * node: the alias node
 *
 * Return: 0 if successful, 1 if failed
 */
int display_alias(list_t *node)
{
	char *equal_pos, *alias_name;

	if (node)
	{
		equal_pos = _strchr(node->str, '=');
		for (alias_name = node->str; alias_name <= equal_pos; alias_name++)
			_putchar(*alias_name);
		_putchar('\'');
		_puts(equal_pos + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * myalias: handles the alias built-in command
 * 
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i;
	char *equal_pos;
	list_t *node;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			display_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		equal_pos = _strchr(info->argv[i], '=');
		if (equal_pos)
			add_alias(info, info->argv[i]);
		else
			display_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
