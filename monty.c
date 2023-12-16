#include "monty.h"

app_var_t app_var;

/**
 * get_operation_name - get the bytecode operation name
 * @clean_line: the clean line string
 * Return: the operation name
 */
char *get_operation_name(char *clean_line)
{
	int space_pos;
	char *operation;
	app_err_t *app_err = app_var.app_err;

	space_pos = str_contains_char(clean_line, ' ');
	if (space_pos != -1)
	{
		operation = str_cut(clean_line, 0, space_pos);
		if (app_err)
			return (NULL);
	}
	else
	{
		operation = _strcpy(clean_line);
		if (app_err)
			return (NULL);
	}

	return (operation);
}

/**
 * get_operation_arg - get the bytecode operation arg
 * @cline: the clean line string
 * Return: the operation arg
 */
char *get_operation_arg(char *cline)
{
	char *arg = NULL;
	int space_pos;
	app_err_t *app_err = app_var.app_err;

	space_pos = str_contains_char(cline, ' ');
	if (space_pos != -1)
	{
		arg = str_clean_spaces_se(str_cut(cline, space_pos, strlen(cline)));
		if (app_err)
			return (NULL);

		space_pos = str_contains_char(arg, ' ');
		if (space_pos != -1)
		{
			arg = str_cut(arg, 0, space_pos);
			if (app_err)
				return (NULL);
		}
	}

	return (arg);
}

/**
 * get_op_and_exe - get operation and execute
 * @operation: the operation name
 * @arg: the operation arg
 * Return: 1 success, 0 error
 */
int get_op_and_exe(char *operation, char *arg)
{
	char *line;
	unsigned int ln;
	command_line_t *current_command_line = app_var.current_command_line;
	app_err_t *app_err = app_var.app_err;

	line = current_command_line->line;
	ln = current_command_line->line_number;

	current_command_line->arg = _strcpy(arg);
	if (app_err)
		return (0);

	get_operation_func(operation);
	if (current_command_line->op_func)
	{
		current_command_line->op_func(&app_var.global_stack, ln);
		if (app_err)
			return (0);
	}
	else
	{
		make_sntx_err("L%d: unknown instruction %s\n", ln, line);
		return (0);
	}

	return (1);
}

/**
 * execute_command_line - execute the current command line
 * @line: the line we want to parse
 * @line_number: the number of line in file
 * Return: 1 success, 0 error
 */
int execute_command_line(char *line, unsigned int line_number)
{
	int line_len, status = 1;
	char *cline = NULL;
	char *operation = NULL, *arg = NULL;
	command_line_t *current_command_line = app_var.current_command_line;
	app_err_t *app_err = app_var.app_err;

	current_command_line->line = _strcpy(line);
	if (app_err)
		return (0);
	current_command_line->line_number = line_number;
	current_command_line->arg = NULL;
	current_command_line->op_func = NULL;

	cline = str_clean_spaces_se(line);
	if (app_err)
		return (0);

	line_len = strlen(cline);
	if (cline[0] != '#' && line_len != 0)
	{
		operation = get_operation_name(cline);
		if (app_err)
			status = 0;
		else
		{
			arg = get_operation_arg(cline);
			if (app_err)
				status = 0;
		}

		if (status)
			status = get_op_and_exe(operation, arg);
	}

	if (cline)
		cline = _free(cline);
	if (operation)
		operation = _free(operation);
	if (arg)
		arg = _free(arg);

	reset_current_command_line();

	return (status);
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

	app_var.global_stack = NULL;
	app_var.stack_mode = LIFO_T;
	app_var.app_err = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_failure();
	}

	filename = argv[1];

	app_var.current_command_line = malloc(sizeof(command_line_t));
	if (!app_var.current_command_line)
		exit_with_malloc_err();

	file_read_lines(filename, execute_command_line);

	reset_current_command_line();
	app_var.global_stack = dll_free(app_var.global_stack);

	if (app_var.app_err)
		exit_with_app_err();

	return (EXIT_SUCCESS);
}
