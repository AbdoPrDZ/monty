#include "monty.h"
#include <stdlib.h>

/**
 * exit_with_error - exit the program with error
 * @error: the error message
 */
void exit_with_error(const char *error, ...)
{
	va_list args;

	va_start(args, error);
	vfprintf(stderr, error, args);
	va_end(args);

	exit(EXIT_FAILURE);
}
