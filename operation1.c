#include "monty.h"

/**
 * get_operation_func - get the operation func of current command line
 */
void get_operation_func(void)
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
		{NULL, NULL},
	};

	current_command_line->instruction = NULL;

	for (i = 0; operations[i].opcode != NULL; i++)
		if (strcmp(operations[i].opcode, current_command_line->operation) == 0)
		{
			current_command_line->instruction = &operations[i];
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
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(current_command_line->arg);
	*stack = dll_add(stack, n);
}

/**
 * op_pall - print all element of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
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
	stack_t *node = *stack;

	if (!node)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (node->prev)
		node = node->prev;

	fprintf(stdout, "%d\n", node->n);
}

/**
 * op_pop - remove the element on the top of stack
 * @stack: the stack
 * @line_number: the number of line in file
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = dll_pop(*stack);
}
