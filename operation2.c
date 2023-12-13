#include "monty.h"

/**
 * op_swap - swap the two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second, *thread;

	if (!first || !first->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (first->prev)
		first = first->prev;

	second = first->next;
	thread = second->next;

	if (thread)
		first->next = thread;
	else
		first->next = NULL;
	thread->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}

/**
 * op_add - calculate the addition of two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second;

	if (!first || !first->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (first->prev)
		first = first->prev;
	second = first->next;

	second->n = first->n + second->n;
	first->next = NULL;
	second->prev = NULL;
	free(first);

	*stack = second;
}

/**
 * op_nop - do not anythings
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
