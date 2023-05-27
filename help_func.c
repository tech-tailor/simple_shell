#include "simple_shell.h"

/**
 * free_par - A function that frees all te memory aled for cd
 * @cmd: The pointer to allocated memory ee
 * Return: Nothi
 */
void free_par(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
}


/**
 * free_exit - A function that frees ll the memory it
 * @cmd: The pointer to allocated md memory to fre
 * Return: Nothig
 */
void free_exit(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
	exit(EXIT_FAILURE);
}

/**
 * check - the function that checks
 * @cmd: the comand
 * @av: the argument from terminal
 * @circl: times of circl
 * @envpp: the enviroment
 * Return: Nothing
 */
void check(char **cmd, char **av, char **envpp, int *circl)
{
	int ac = 0;

	while (cmd[ac] != NULL)
		ac++;
	if (_strcmp(cmd[0], "exit") != 0)
		shell_exit(cmd);
	else if (_strcmp(cmd[0], "cd") != 0)
	{
		_cd(cmd[1]);
		free_par(cmd);
	}
	else if (_strcmp(cmd[0], "env") != 0)
	{
		print_envp(envpp);
		free_par(cmd);
	}
	else if ((_strcmp(cmd[0], "setenv") != 0) && (ac > 2))
	{
		shell_setenv(cmd[1], cmd[2]);
		free_par(cmd);
	}
	else if ((_strcmp(cmd[0], "unsetenv") != 0) && (ac > 1))
	{
		shell_unsetenv(cmd[1]);
		free_par(cmd);
	}
	else
		create_fork(cmd, av[0], envpp, *circl);
}
