#include "simple_shell.h"

/**
  * change_dir - function that works cd
  * @path: path to then directory
  * Return: 0 on success, -1 on failure.
  */
int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}

/**
 * shell_exit - exits the shell function.
 * @cmd: The pointer to parameters.
 * Return: Nothing.
 */
void shell_exit(char **cmd)
{
	int test = 0;

	if (cmd[1] == NULL)
	{
		free_par(cmd);
		exit(EXIT_SUCCESS);
	}

	test = _atoi(cmd[1]);
	free_par(cmd);
	exit(test);
}
