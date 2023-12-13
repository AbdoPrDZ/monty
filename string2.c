#include "monty.h"

/**
 * str_is_int - check if the string is int
 * @str: the string
 * Return: 1 if is int, 0 if not
 */
int str_is_int(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);

	return (1);
}
