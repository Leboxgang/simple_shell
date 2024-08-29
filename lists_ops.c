#include "shell.h"

/* add_node: Inserts a new node at the start of the list
 * @head: Double pointer to the head of the list
 * @str: String data to be stored in the new node
 * @num: Index number associated with the node (used in history)
 *
 * Return: Pointer to the new head of the list, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);

	new_head = malloc(sizeof(list_t)); /* Allocate memory for the new node */
	if (!new_head)
		return (NULL);

	_memset((void *)new_head, 0, sizeof(list_t)); /* Zero out the new node */
	new_head->num = num; /* Set the node index */

	if (str)
	{
		new_head->str = _strdup(str); /* Duplicate the string for storage in the node */
		if (!new_head->str)
		{
			free(new_head); /* Clean up if string duplication fails */
			return (NULL);
		}
	}

	new_head->next = *head; /* Link the new node to the previous head */
	*head = new_head; /* Update the head to the new node */
	
	return (new_head);
}

/* add_node_end - Appends a node to the end of the list
 * @head: Double pointer to the head of the list
 * @str: String data to be stored in the new node
 * @num: Index number associated with the node (used in history)
 *
 * Return: Pointer to the new node, or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}

	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/* print_list_str: Prints the string content of each node in the list
 * @h: Pointer to the first node in the list
 *
 * Return: Number of nodes in the list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}

	return (i);
}

/* delete_node_at_index: Removes the node at a specified index
 * @head: Double pointer to the head of the list
 * @index: Position of the node to delete
 *
 * Return: 1 if successful, 0 otherwise
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);
	
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}

	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}

	return (0);
}

/* free_list: Frees the entire linked list
 * @head_ptr: Double pointer to the head of the list
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;

	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
