#include "monty.h"

/**
 * _strcpy - copy string into new string
 * @str: the string
 * Return: the copy of string
 */
char *_strcpy(char *str)
{
	int i, str_len;
	char *cpy;

	if (!str)
		return (NULL);

	str_len = strlen(str);

	cpy = malloc(sizeof(char) * (str_len + 1));
	if (cpy == NULL)
	{
		make_malloc_err();
		return (NULL);
	}

	for (i = 0; i < str_len; i++)
		cpy[i] = str[i];

	cpy[i] = '\0';

	return (cpy);
}

/**
 * str_rev - reverse string.
 * @str: the string.
 * Return: reversed string.
 */
char *str_rev(char *str)
{
	int i, len;
	char *reversed;

	if (str == NULL)
		return (NULL);

	len = strlen(str);

	reversed = malloc(sizeof(char) * (len + 1));
	if (reversed == NULL)
	{
		make_malloc_err();
		return (NULL);
	}

	for (i = 0; i < len; i++)
		reversed[i] = str[len - i - 1];

	reversed[len] = '\0';

	return (reversed);
}

/**
 * str_contains_char - check if char target exists on string
 * @str: the string.
 * @target: search char target
 * Return: target pos, -1 if not exists.
 */
int str_contains_char(char *str, char target)
{
	int i, slen;

	if (str)
	{
		slen = strlen(str);

		for (i = 0; i < slen; i++)
			if (str[i] == target)
				return (i);
	}

	return (-1);
}

/**
 * str_cut - cut part of str.
 * @str: string want to cut.
 * @s: string pos.
 * @e: string pos.
 * Return: the part of string.
 */
char *str_cut(char *str, const int s, const int e)
{
	int i, j, len = strlen(str);
	char *cstr;

	if (str == NULL || s > e || e > len)
		return (NULL);

	cstr = malloc(sizeof(char) * (e - s + 1));
	if (cstr == NULL)
	{
		make_malloc_err();
		return (NULL);
	}

	for (i = s, j = 0; i < e; i++, j++)
		cstr[j] = str[i];

	cstr[j] = '\0';

	return (cstr);
}

/**
 * str_clean_spaces_se - clean str from spaces in start and end
 * @str: the string want to clean.
 * Return: cleaned string or NULL on error.
 */
char *str_clean_spaces_se(char *str)
{
	int i = 0, start = 0, end = 0, len;
	char *cstr, *rstr;
	app_err_t *app_err = app_var.app_err;

	if (str == NULL)
		return (NULL);

	len = strlen(str);

	while (str[i] && str[i] == ' ')
		start++, i++;

	rstr = str_rev(str);
	if (rstr == NULL && app_err)
		return (NULL);

	i = 0;
	while (rstr[i] && rstr[i] == ' ')
		end++, i++;

	end = len - end;

	cstr = str_cut(str, start, end);
	if (cstr == NULL && app_err)
		return (NULL);

	return (cstr);
}
