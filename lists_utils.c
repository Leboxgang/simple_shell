#include "shell.h"

/* list_len: Calculates the length of the linked list
 * @h: Pointer to the first node in the list
 *
 * Return: Number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/* list_to_strings: Converts the linked list to an array of strings
 * @head: Pointer to the first node in the list
 *
 * Return: Array of strings, or NULL if allocation fails
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);

	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);

	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/* print_list: Outputs all elements of the linked list
 * @h: Pointer to the first node in the list
 *
 * Return: Number of nodes printed
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/* node_starts_with: Finds a node with a string that starts with a given prefix
 * @node: Pointer to the head of the list
 * @prefix: The prefix string to search for
 * @c: The character following the prefix, or -1 for any character
 *
 * Return: Pointer to the matched node, or NULL if no match is found
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/* get_node_index: Retrieves the index of a specified node
 * @head: Pointer to the first node in the list
 * @node: Pointer to the node whose index is needed
 *
 * Return: The index of the node, or -1 if the node is not found
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
