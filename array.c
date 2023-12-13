#include "array.h"
#include "utils.h"
#include "string.h"

/**
 * arr_len - get array length
 * @arr: the array
 * Return: the length of array
 */
int arr_len(char **arr)
{
	int i = 0;

	if (arr)
		while (arr[i])
			i++;

	return (i);
}

/**
 * arr_add - add item to array
 * @arr: the array
 * @item: the item
 * Return: new array
 */
char **arr_add(char **arr, const char *item)
{
	int alen = 0;

	if (!arr)
		arr = malloc(sizeof(char) * 1);
	else
	{
		alen = arr_len(arr);
		arr = _realloc(arr, sizeof(char *) * (alen + 2), sizeof(char *) * (alen + 3));
	}

	if (!arr)
		exit_with_error("Error: malloc failed\n");

	arr[alen] = _strcpy(item);
	arr[alen + 1] = NULL;

	return (arr);
}
