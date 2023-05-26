#include "simple_shell.h"

/**
 * execute - A function that executes
 * @commands: The pointer to parameters
 * @name: The name of the shell.
 * @envp: The pointer to the enviromental
 * @cicl: times the terminal executed
 * Return: Nothing
 */
void execute(char **commands, char *name, char **envp, int cicl)
{
	char **pathways = NULL, *path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(commands[0], "env") != 0)
		print_env(envp);
	if (stat(commands[0], &st) == 0)
	{
		if (execve(commands[0], commands, envp) < 0)
		{
			perror(name);
			free_exit(commands);
		}
	}
	else
	{
		pathways = _getPATH(envp);
		while (pathways[i])
		{
			path = _strcat(pathways[i], commands[0]);
			i++;

			if (stat(path, &st) == 0)
			{
				if (execve(path, commands, envp) < 0)
				{
					perror(name);
					free_par(pathways);
					free_exit(commands);
				}
				return;
			}
		}
		print_error(name, cicl, commands);
		free_par(pathways);
	}
}

/**
 * print_env - A function that prints envirntal variables
 * @envp: The pointer to enviroment variables
 * Return: Nothing
 */
void print_env(char **envp)
{
	size_t i = 0, len = 0;

	while (envp[i])
	{
		len = _strlen(envp[i]);
		write(STDOUT_FILENO, envp[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
