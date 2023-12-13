#include "lists.h"
#include "utils.h"

/**
 * dll_add - add node to doubly linked list int
 * @head: the head of doubly linked list int
 * @n: the value
 * Return: the head of doubly linked list int if success, NULL if not
 */
stack_t *dll_add(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		exit_with_error("Error: malloc failed\n");

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (new);
}

/**
 * dll_get_at_index - get node at index from doubly lined list int
 * @head: the head of doubly linked list int
 * @index: the position of node
 * Return: the node if exists, NULL if not exists
 */
stack_t *dll_get_at_index(stack_t **head, unsigned int index)
{
	stack_t *node;
	unsigned int i = 0;

	if (!(*head) || (int)index < 0)
		return (NULL);

	node = *head;
	if (node && node->prev)
		while (node->prev)
			node = node->prev;

	while (node)
	{
		if (i == index)
			return (node);
		node = node->next;
		i++;
	}

	return (NULL);
}

/**
 * dll_pop - pop the first element of doubly linked list int
 * @head: the head of doubly linked list int
 * Return: the head of modified doubly linked list int
 */
stack_t *dll_pop(stack_t *head)
{
	stack_t *tmp;

	if (head)
	{
		while (head->prev)
			head = head->prev;

		tmp = head->next;
		if (tmp)
		{
			tmp->prev = NULL;
			head->next = NULL;
			free(head);
			head = tmp;
		}
		else
		{
			free(head);
			head = NULL;
		}
	}

	return (head);
}

/**
 * dll_free - free doubly linked list int
 * @head: the head of doubly linked list int
 */
void dll_free(stack_t *head)
{
	stack_t *next;

	if (head)
	{
		while (head->prev)
			head = head->prev;

		while (head)
		{
			next = head->next;
			free(head);
			head = next;
		}
	}
}
