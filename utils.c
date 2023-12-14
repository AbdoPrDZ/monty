#include "monty.h"

/**
 * exit_with_malloc_error - exit the program with malloc error
 */
void exit_with_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");

	if (global_stack)
		dll_free(global_stack);

	exit(EXIT_FAILURE);
}

/**
 * exit_with_sntx_error - exit the program with syntax error
 * @error: the error message
 * @line_number: the line number of syntax error
 */
void exit_with_sntx_error(const char *error, unsigned int line_number)
{
	fprintf(stderr, error, line_number);

	if (global_stack)
		dll_free(global_stack);

	exit(EXIT_FAILURE);
}

/**
 * exit_with_error - exit the program with error
 * @error: the error message
 */
void exit_with_error(const char *error, ...)
{
	va_list args;

	va_start(args, error);
	fprintf(stderr, error, args);
	va_end(args);

	if (global_stack)
		dll_free(global_stack);

	exit(EXIT_FAILURE);
}
