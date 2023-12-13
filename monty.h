#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "operation.h"

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command_line_s - the current line options
 * @line_number: the current command line line number
 * @line: the current command line line string
 * @operation: the current command line operation name
 * @arg: the current command line operation arg
 * @instruction: the current command line instruction
 */
typedef struct command_line_s
{
	int line_number;
	char *line;
	char *operation;
	char *arg;
	instruction_t *instruction;
} command_line_t;

extern command_line_t *current_command_line;

void parse_command_line(const char *line, int line_number);
void get_operation_func(void);

#endif /* _MONTY_H_ */
