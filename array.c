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
	int i, alen = 0;
	char **new_arr;

	if (arr)
		alen = arr_len(arr);

	new_arr = malloc(sizeof(char *) * (alen + 3));
	if (!new_arr)
		exit_with_error("Error: malloc failed, alen: %d\n", alen);

	for (i = 0; i < alen; i++)
		new_arr[i] = arr[i];

	new_arr[alen] = _strcpy(item);
	new_arr[alen + 1] = NULL;

	return (new_arr);
}
