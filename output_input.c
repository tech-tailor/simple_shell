#include "simple_shell.h"

/**
 * display_prompt - display the prompt
 * Return: Nothing
 */
void display_prompt(void)
{
	static unsigned int is_first_time = 1;

	while (is_first_time)
	{
		is_first_time = 0;
	}
	printf("$ ");
}

/**
 * read_data - the function that get command from terminal
 * @cmd: The first argument
 * @par: the pointer to the parameter vector
 * Return: Nothing
 */
void read_data(char *cmd, char **par)
{
	char *line = NULL, *arr[10], *token;
	size_t i = 0, j = 0, buffsize = 0;
	ssize_t len = -1;

	len = _getline(&line, &buffsize, stdin);
	if (len == 0 || len == -1)
	{
		free(line);
		return;
	}
	fflush(stdin);
	token = strtok(line, " \n");

	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n");
	}
	_strcpy(cmd, arr[0]);

	for (j = 0; j < i; j++)
	{
		par[j] = arr[j];
	}
	par[i] = NULL;
	free(line);
}
