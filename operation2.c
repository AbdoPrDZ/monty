#include "monty.h"

/**
 * op_swap - swap the two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = stack ? *stack : NULL;
	stack_t *second, *thread;

	if (first == NULL)
		make_sntx_err("L%d: can't swap, stack too short\n", line_number, NULL);
	else
	{
		while (first->prev)
			first = first->prev;

		if (first->next == NULL)
			make_sntx_err("L%d: can't swap, stack too short\n", line_number, NULL);
		else
		{
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
	}
}

/**
 * op_add - calculate the addition of two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first = stack ? *stack : NULL;
	stack_t *second;

	if (first == NULL)
		make_sntx_err("L%d: can't add, stack too short\n", line_number, NULL);
	else
	{
		while (first->prev)
			first = first->prev;

		if (first->next == NULL)
			make_sntx_err("L%d: can't add, stack too short\n", line_number, NULL);
		else
		{
			second = first->next;

			second->n = first->n + second->n;
			first->next = NULL;
			second->prev = NULL;
			first = _free(first);

			*stack = second;
		}
	}
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

/**
 * op_sub - calculate the subtracts of two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first = stack ? *stack : NULL;
	stack_t *second;

	if (first == NULL)
		make_sntx_err("L%d: can't sub, stack too short\n", line_number, NULL);
	else
	{
		while (first->prev)
			first = first->prev;

		if (first->next == NULL)
			make_sntx_err("L%d: can't sub, stack too short\n", line_number, NULL);
		else
		{
			second = first->next;

			second->n = second->n - first->n;
			first->next = NULL;
			second->prev = NULL;
			first = _free(first);

			*stack = second;
		}
	}
}

/**
 * op_div - calculate the division of two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first = stack ? *stack : NULL;
	stack_t *second;

	if (first == NULL)
		make_sntx_err("L%d: can't div, stack too short\n", line_number, NULL);
	else
	{
		while (first->prev)
			first = first->prev;

		if (first->next == NULL)
			make_sntx_err("L%d: can't div, stack too short\n", line_number, NULL);
		else
		{
			second = first->next;

			if (first->n == 0)
				make_sntx_err("L%d: division by zero\n", line_number, NULL);
			else
			{
				second->n = second->n / first->n;
				first->next = NULL;
				second->prev = NULL;
				first = _free(first);

				*stack = second;
			}
		}
	}
}
