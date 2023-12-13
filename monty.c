#include "monty.h"
#include "file.h"
#include "array.h"
#include "string.h"

command_line_t *current_command_line;

/**
 * parse_command_line - parse command line
 * @line: the line we want to parse
 * @line_number: the number of line in file
 */
void parse_command_line(const char *line, int line_number)
{
	int space_pos, line_len;
	char *cline;
	char *operation, *arg = NULL;

	cline = str_clean_spaces_se(line);
	line_len = strlen(cline);
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

	current_command_line->line_number = line_number;
	current_command_line->line = cline;
	current_command_line->operation = operation;
	current_command_line->arg = arg;
	get_operation_func();
	if (!current_command_line->instruction)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - the main of monty app
 * @argc: argument count
 * @argv: arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack;
	char *filename, **lines;
	int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	if (!file_exists(filename))
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	lines = file_read_lines(filename);

	current_command_line = malloc(sizeof(command_line_t));
	if (!current_command_line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; lines[i] != NULL; i++)
	{
		parse_command_line(lines[i], i);
		if (current_command_line->instruction != NULL)
			current_command_line->instruction->f(&stack, i);
	}
	free(current_command_line);

	if (stack)
		dll_free(stack);

	return (EXIT_SUCCESS);
}
