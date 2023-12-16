#include "monty.h"

/**
 * str_is_int - check if the string is int
 * @str: the string
 * Return: 1 if is int, 0 if not
 */
int str_is_int(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);

	return (1);
}

/**
 * str_add_char - add char to the string
 * @str: the string
 * @c: the char
 * Return: the new string
 */
char *str_add_char(char *str, char c)
{
	int i = 0, str_len = 0;
	char *new_str;

	if (str)
		str_len = strlen(str);

	new_str = malloc(sizeof(char) * (str_len + 2));
	if (!new_str)
	{
		make_malloc_err();
		return (NULL);
	}

	for (i = 0; i < str_len; i++)
		new_str[i] = str[i];

	new_str[i] = c;
	new_str[i + 1] = '\0';

	return (new_str);
}
