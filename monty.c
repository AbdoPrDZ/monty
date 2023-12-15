#include "monty.h"

command_line_t *current_command_line;
stack_t *global_stack;
char *stack_mode;

/**
 * execute_command_line - execute the current command line
 * @line: the line we want to parse
 * @line_number: the number of line in file
 */
void execute_command_line(const char *line, unsigned int line_number)
{
	int space_pos, line_len;
	char *cline;
	char *operation, *arg = NULL;

	current_command_line->arg = NULL;
	current_command_line->op_func = NULL;
	cline = str_clean_spaces_se(line);
	line_len = strlen(cline);
	if (cline[0] != '#' && line_len != 0)
	{
		space_pos = str_contains_char(cline, ' ');
		if (space_pos != -1)
		{
			operation = str_cut(cline, 0, space_pos);
			arg = str_clean_spaces_se(str_cut(cline, space_pos, line_len));
			space_pos = str_contains_char(arg, ' ');
			if (space_pos != -1)
				arg = str_cut(arg, 0, space_pos);
		}
		else
			operation = cline;

		current_command_line->arg = arg;
		get_operation_func(operation);

		if (current_command_line->op_func)
			current_command_line->op_func(&global_stack, line_number);
		else
		{
			if (global_stack)
				dll_free(global_stack);

			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);

			exit(EXIT_FAILURE);
		}
	}
	free(cline);
}

/**
 * main - the main of monty app
 * @argc: argument count
 * @argv: arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];

	global_stack = NULL;
	stack_mode = "LIFO";
	current_command_line = malloc(sizeof(command_line_t));
	if (!current_command_line)
		exit_with_malloc_error();

	file_read_lines(filename, execute_command_line);

	if (global_stack)
		dll_free(global_stack);

	return (EXIT_SUCCESS);
}
