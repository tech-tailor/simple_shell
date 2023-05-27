#include "simple_shell.h"

/**
 * execute - A function that xecutes a cm
 * @cmd: The pointer to tokiezed cmd
 * @name: The name of the shell
 * @envp: The pointer to the epiromental variables.
 * @circl: Number of executed rcl
 * Return: Nothing
 */
void execute(char **cmd, char *name, char **envp, int circl)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(cmd[0], "envp") != 0)
		print_envp(envp);

	if (stat(cmd[0], &st) == 0)
	{
		if (execve(cmd[0], cmd, envp) < 0)
		{
			perror(name);
			free_exit(cmd);
		}
	}
	else
	{
		pathways = _getPATH(envp);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], cmd[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, cmd, envp) < 0)
				{
					perror(name);
					free_par(pathways);
					free_exit(cmd);
				}
				return;
			}
		}
		print_error(name, circl, cmd);
		free_par(pathways);
	}
}


/**
 * print_envp - A function that printsall envpiromental variab
 * @envp: The pointer topiromentalariables
 * Return: Nothing
 */
void print_envp(char **envp)
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


/**
 * _getPATH - A function to gets the full value fro
 * @envp: The pointer to envpiromental variabls
 * Return: All tokeized pathways for cmds
 */
char **_getPATH(char **envp)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(envp[i], "=");
	while (envp[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = _strtok(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(envp[i], "=");
	}
	return (NULL);
}


/**
 * print_error - A function that prints essage not found
 * @name: The name of the shell
 * @circl: Number of circl
 * @cmd: The pointer to tkenized cmd.
 * Return: Nothing.
 */
void print_error(char *name, int circl, char **cmd)
{
	char c;

	c = circl + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd[0], _strlen(cmd[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
