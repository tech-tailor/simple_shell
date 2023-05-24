#include "simple_shell.h"

/**
 * _getline - the function used to get line fromm terminal
 * @lineptr: address to the pointer
 * @n: size of the characters
 * @stream: read from terminal
 * Return: sizeo of character on succed otherwise -1
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = NULL, buffer[20];
	size_t size = 0, len = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while (fgets(buffer, 20, stdin) != NULL)
	{
		len = strlen(buffer);
		size += len;
		if (size >= *n)
			*n = size;
		line = realloc(*lineptr, *n);
		if (line == NULL)
			return (-1);
		strncpy(line, buffer, len);
		if (line[*n - 1] == '\n')
			break;
	}
	*lineptr =  line;
	return (*n);
}
