#include "monty.h"

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
		exit_with_file_error(filename);

	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	content = (char *)malloc(file_size + 1);
	if (!content)
	{
		fclose(file);
		exit_with_malloc_error();
	}

	bytes_read = fread(content, 1, file_size, file);
	if (bytes_read != (size_t)file_size)
	{
		fclose(file);
		free(content);
		exit_with_file_error(filename);
	}

	content[file_size] = '\0';

	fclose(file);

	return (content);
}

/**
 * file_read_lines - get file lines
 * @filename: the file name
 * @reader: the reader function that receive the lines
 */
void file_read_lines(const char *filename, lines_reader reader)
{
	char *content, *line = NULL;
	int i, line_number = 1, line_start = 0, line_end = 0;

	content = file_read(filename);

	for (i = 0; content[i] != '\0'; i++)
		if (content[i] == '\n' || content[i + 1] == '\0')
		{
			line_end = i + (content[i + 1] == '\0' && content[i] != '\n' ? 1 : 0);
			line = str_cut(content, line_start, line_end);
			reader(line, line_number);
			line_number++;
			line_start = i + 1;
		}

	if (line)
		free(line);
	free(content);
}
