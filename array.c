#include "array.h"
#include "string.h"

/**
 * arr_len - get array length
 * @arr: the array
 * Return: the length of array
 */
int arr_len(char **arr)
{
	int i = 0;

	if (!arr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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
		arr = realloc(arr, sizeof(char *) * (alen + 2));
	}

	if (!arr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	arr[alen] = _strcpy(item);
	arr[alen + 1] = NULL;

	return (arr);
}
