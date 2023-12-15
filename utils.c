#include "monty.h"

/**
 * exit_with_malloc_error - exit the program with malloc error
 */
void exit_with_malloc_error(void)
{
	if (global_stack)
		dll_free(global_stack);

	fprintf(stderr, "Error: malloc failed\n");

	exit(EXIT_FAILURE);
}

/**
 * exit_with_sntx_error - exit the program with syntax error
 * @error: the error message
 * @line_number: the line number of syntax error
 */
void exit_with_sntx_error(const char *error, unsigned int line_number)
{
	if (global_stack)
		dll_free(global_stack);

	fprintf(stderr, error, line_number);

	exit(EXIT_FAILURE);
}

/**
 * exit_with_file_error - exit the program with file error
 * @filename: the file name
 */
void exit_with_file_error(const char *filename)
{
	if (global_stack)
		dll_free(global_stack);

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
