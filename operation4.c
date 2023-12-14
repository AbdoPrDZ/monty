#include "monty.h"

/**
 * op_rotr - rotate the stack top bottom
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack ? *stack : NULL;
	int last_n;
	(void)line_number;

	if (node && node->next)
	{
		node = *stack;

		while (node->next)
			node = node->next;

		last_n = node->n;

		while (node->prev)
		{
			node = node->prev;
			node->next->n = node->n;
		}
		node->n = last_n;

		*stack = node;
	}
}

/**
 * op_stack - set stack mode to LIFO mode
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_mode = "LIFO";
}

/**
 * op_queue - set stack mode to FIFO mode
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_mode = "FIFO";
}
