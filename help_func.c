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
