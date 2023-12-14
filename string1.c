#include "monty.h"

/**
 * _strcpy - copy string into new string
 * @str: the string
 * Return: the copy of string
 */
char *_strcpy(const char *str)
{
	char *cpy;

	cpy = malloc(sizeof(char) * strlen(str));
	strcpy(cpy, str);

	return (cpy);
}

/**
 * str_rev - reverse string.
 * @str: the string.
 * Return: reversed string.
 */
char *str_rev(const char *str)
{
	int i, len = strlen(str);
	char *reversed = (char *)malloc(len + 1);

	if (reversed == NULL)
		return (NULL);

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
int str_contains_char(const char *str, const char target)
{
	int i, slen = strlen(str);

	for (i = 0; i < slen; i++)
		if (str[i] == target)
			return (i);

	return (-1);
}

/**
 * str_cut - cut part of str.
 * @str: string want to cut.
 * @s: string pos.
 * @e: string pos.
 * Return: the part of string.
 */
char *str_cut(const char *str, const int s, const int e)
{
	int i, j, len = strlen(str);
	char *cstr;

	if (!str || s > e || e > len)
		return (NULL);

	cstr = malloc(sizeof(char) * (e - s + 1));
	if (!cstr)
		exit_with_malloc_error();

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
char *str_clean_spaces_se(const char *str)
{
	int i = 0, start = 0, end = 0, len;
	char *cstr, *rstr;

	if (!str)
		return (NULL);

	len = strlen(str);

	while (str[i] && str[i] == ' ')
		start++, i++;

	rstr = str_rev(str);

	i = 0;
	while (rstr[i] && rstr[i] == ' ')
		end++, i++;

	end = len - end;

	cstr = malloc(sizeof(char) * (end - start + 1));
	if (cstr)
	{
		strncpy(cstr, str + start, (end - start));
		cstr[end - start] = '\0';
	}

	return (cstr);
}
