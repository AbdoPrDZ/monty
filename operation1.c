#include "monty.h"

/**
 * get_operation_func - get the operation func of current command line
 * @operation_name: the operation name
 */
void get_operation_func(char *operation_name)
{
	int i;
	instruction_t operations[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL},
	};

	current_command_line->op_func = NULL;

	for (i = 0; operations[i].opcode != NULL; i++)
		if (strcmp(operations[i].opcode, operation_name) == 0)
		{
			current_command_line->op_func = operations[i].f;
			break;
		}
}

/**
 * op_push - push int to a stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int n;
	(void)line_number;

	if (!current_command_line->arg || !str_is_int(current_command_line->arg))
		make_sntx_err("L%d: usage: push integer\n", line_number, NULL);
	else
	{
		n = atoi(current_command_line->arg);
		if (strcmp(stack_mode, "LIFO") == 0)
			*stack = dll_add(stack, n);
		else
			*stack = dll_add_end(stack, n);
	}
}

/**
 * op_pall - print all element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack ? *stack : NULL;
	(void)line_number;

	if (node)
	{
		while (node->prev)
			node = node->prev;

		while (node)
		{
			fprintf(stdout, "%d\n", node->n);
			node = node->next;
		}
	}
}

/**
 * op_pint - print the element on the top of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack ? *stack : NULL;

	if (node == NULL)
		make_sntx_err("L%d: can't pint, stack empty\n", line_number, NULL);
	else
	{
		while (node->prev)
			node = node->prev;

		fprintf(stdout, "%d\n", node->n);
	}
}

/**
 * op_pop - remove the element on the top of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = stack ? *stack : NULL;

	if (node == NULL)
		make_sntx_err("L%d: can't pop, stack empty\n", line_number, NULL);
	else
	{
		if (strcmp(stack_mode, "FIFO") == 0)
			*stack = dll_pop(*stack);
		else
			*stack = dll_pop_end(*stack);
	}
}
