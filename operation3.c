#include "monty.h"

/**
 * op_mul - calculate the multiple of two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = stack ? *stack : NULL;
	stack_t *second;

	if (first == NULL)
		make_sntx_err("L%d: can't mul, stack too short\n", line_number, NULL);
	else
	{
		while (first->prev)
			first = first->prev;

		if (first->next == NULL)
			make_sntx_err("L%d: can't mul, stack too short\n", line_number, NULL);
		else
		{
			second = first->next;

			second->n = first->n * second->n;
			first->next = NULL;
			second->prev = NULL;
			first = _free(first);

			*stack = second;
		}
	}
}

/**
 * op_mod - calculate the mod of two first element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first = stack ? *stack : NULL;
	stack_t *second;

	if (first == NULL)
		make_sntx_err("L%d: can't mod, stack too short\n", line_number, NULL);
	else
	{
		while (first->prev)
			first = first->prev;

		if (first->next == NULL)
			make_sntx_err("L%d: can't mod, stack too short\n", line_number, NULL);
		else
		{
			second = first->next;

			if (first->n == 0)
				make_sntx_err("L%d: division by zero\n", line_number, NULL);
			else
			{
				second->n = second->n % first->n;
				first->next = NULL;
				second->prev = NULL;
				first = _free(first);

				*stack = second;
			}
		}
	}
}

/**
 * op_pchar - putchar the top element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack ? *stack : NULL;

	if (node == NULL)
		make_sntx_err("L%d: can't pchar, stack empty\n", line_number, NULL);
	else
	{
		while (node->prev)
			node = node->prev;

		if (node->n > 0 && node->n <= 127)
			fprintf(stdout, "%c\n", node->n);
		else
			make_sntx_err("L%d: can't pchar, value out of range\n", line_number, NULL);
	}
}

/**
 * op_pstr - putchar the top element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack ? *stack : NULL;
	char *str = "";
	(void)line_number;

	if (node)
	{
		while (node->prev)
			node = node->prev;

		while (node && node->n > 0 && node->n <= 127)
		{
			str = str_add_char(str, node->n);
			node = node->next;
		}
	}

	fprintf(stdout, "%s\n", str);
}

/**
 * op_rotl - rotate the stack to top
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack ? *stack : NULL;
	int first_n;
	(void)line_number;

	if (node)
	{
		node = *stack;

		while (node->prev)
			node = node->prev;

		first_n = node->n;

		while (node->next)
		{
			node = node->next;
			node->prev->n = node->n;
		}
		node->n = first_n;

		*stack = node;
	}
}
