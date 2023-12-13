#include "monty.h"

/**
 * file_exists - check if file is exists
 * @filename: the file name
 * Return: 1 if exists, 0 if not
 */
int file_exists(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file)
	{
		fclose(file);
		return (1);
	}

	return (0);
}

/**
 * file_read - get file content
 * @filename: the file name
 * Return: file content
 */
char *file_read(const char *filename)
{
	long file_size;
	char *content;
	size_t bytes_read;

	FILE *file = fopen(filename, "r");

	if (!file)
		return (NULL);

	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	content = (char *)malloc(file_size + 1);
	if (!content)
	{
		fclose(file);
		exit_with_error("Error: malloc failed\n");
	}

	bytes_read = fread(content, 1, file_size, file);
	if (bytes_read != (size_t)file_size)
	{
		fclose(file);
		free(content);
		return (NULL);
	}

	content[file_size] = '\0';

	fclose(file);

	return (content);
}

/**
 * file_read_lines - get file lines
 * @filename: the file name
 * Return: the lines of file
 */
char **file_read_lines(const char *filename)
{
	char **lines = NULL, *content, *token;

	content = file_read(filename);
	if (!content)
		return (NULL);

	token = strtok(content, "\n");
	while (token != NULL)
	{
		lines = arr_add(lines, token);
		if (!lines)
			return (NULL);
		token = strtok(NULL, "\n");
	}

	free(content);

	return (lines);
}
