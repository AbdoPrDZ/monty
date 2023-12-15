#include "monty.h"

/**
 * exit_with_app_err - exit the app with app error
 */
void exit_with_app_err(void)
{
	if (app_err)
	{
		if (strcmp(app_err->type, MALLOC_err) == 0)
			exit_with_malloc_err();
		else if (strcmp(app_err->type, SYNTAX_err) == 0)
			exit_with_sntx_err();
		else if (strcmp(app_err->type, FILE_err) == 0)
			exit_with_file_err(app_err->filename);
	}
}

/**
 * exit_with_malloc_err - exit the program with malloc error
 */
void exit_with_malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit_failure();
}

/**
 * exit_with_sntx_err - exit the program with syntax error
 */
void exit_with_sntx_err(void)
{
	fprintf(stderr, app_err->error, app_err->line_number, app_err->line);
	app_err->line = _free(app_err->line);
	exit_failure();
}

/**
 * exit_with_file_err - exit the program with file error
 * @filename: the file name
 */
void exit_with_file_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit_failure();
}

/**
 * exit_failure - exit app with failure error
 */
void exit_failure(void)
{
	global_stack = dll_free(global_stack);
	reset_current_command_line();

	exit(EXIT_FAILURE);
}
