#include "monty.h"
#include <stdlib.h>

void exit_with_error(const char *error, ...)
{
	va_list args;

	va_start(args, error);
	vfprintf(stderr, error, args);
	va_end(args);

	exit(EXIT_FAILURE);
}

/**
 * _realloc - reallocates memory block.
 * @ptr: previous pointer.
 * @new_size: new size for our pointer.
 * Return: New resized Pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *new, *old;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (!ptr)
			exit_with_error("Error: malloc failed\n");

		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (!new)
		exit_with_error("Error: malloc failed\n");
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			new[i] = old[i];
		free(ptr);
		for (i = old_size; i < new_size; i++)
			new[i] = '\0';
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			new[i] = old[i];
		free(ptr);
	}

	return (new);
}
