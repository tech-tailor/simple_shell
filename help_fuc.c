#include "simple_shell.h"
/**
 * _atoi - a function that converts string to integer.
 * @s: An input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		if (*s >= '0' && *s <= '9')
		{
			flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (flag == 1)
				break;
		}
		s++;
	}

	if (sign < 0)
	{
		total = (-1 * (total));
	}
	return (total);
}

/**
 * _getPATH - A function to gets enviroment PATH
 * @env: The pointer to enviromental variables
 * Return: All available path
 */
char **_getPATH(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = tokening(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * free_par - function that free the allocated parmeter memory
 * @command: The pointer to allocated memory to free
 * Return: Nothing
 */
void free_par(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
}

/**
 * free_exit - function to exit the program after free memory
 * @command: The pointer to allocated command memory to free
 * Return: Nothing.
 */
void free_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}
