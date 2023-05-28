#include "simple_shell.h"

/**
 * _strtok - A function that split and create a full string cmd.
 * @s: The delimiter for strtok.
 * @buffer: The pointer to input string.
 * Return: A string with full cmd.
 */
char **_strtok(char *buffer, const char *s)
{
	char *token = NULL, **cmds = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	if (strtok(buffer, s) == NULL)
	{
		free(buffer);
		return (NULL);
	}
	cmds = malloc((bufsize + 1) * sizeof(char *));
	if (cmds == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free(cmds);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token != NULL)
	{
		cmds[i] = malloc(_strlen(token) + 1);
		if (cmds[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_par(cmds);
			return (NULL);
		}
		_strcpy(cmds[i], token);
		token = strtok(NULL, s);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}
