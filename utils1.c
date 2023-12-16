#include "monty.h"

/**
 * make_file_err - make app error with file error
 * @filename: the file name
 */
void make_file_err(char *filename)
{

	app_err_t *app_err = malloc(sizeof(app_err_t));
	if (!app_err)
		exit_with_malloc_err();

	app_err->type = FILE_err;
	app_err->error = "Error: Can't open file %s\n";
	app_err->filename = filename;

	app_var.app_err = app_err;
}

/**
 * make_sntx_err - make app error with syntax error
 * @error: the format of error
 * @ln: the bytecode line number
 * @line: the bytecode line
 */
void make_sntx_err(char *error, unsigned int ln, char *line)
{
	app_err_t *app_err = malloc(sizeof(app_err_t));
	if (!app_err)
		exit_with_malloc_err();

	app_err->type = SYNTAX_err;
	app_err->error = error;
	app_err->line = _strcpy(line);
	app_err->line_number = ln;

	app_var.app_err = app_err;
}

/**
 * make_malloc_err - make app error with malloc error
 */
void make_malloc_err(void)
{
	app_err_t *app_err = malloc(sizeof(app_err_t));
	if (!app_err)
		exit_with_malloc_err();

	app_err->type = MALLOC_err;
	app_var.app_err = app_err;
}

/**
 * reset_current_command_line - reset current command line data
 */
void reset_current_command_line(void)
{
	command_line_t *current_command_line = app_var.current_command_line;

	if (current_command_line)
	{
		current_command_line->line = _free(current_command_line->line);
		current_command_line->arg = _free(current_command_line->arg);
		current_command_line->line_number = 0;
		current_command_line->op_func = NULL;
	}
}

/**
 * _free - free pointer
 */
void *_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}
