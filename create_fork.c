#include "simple_shell.h"

/**
 * create_fork - A function thareates sub process
 * @cmd: The pointer to tokenied cmd
 * @name: The pointer to the nm f shell.
 * @envp: The pointer to the eniomental variables.
 * @circl: Number of executed cic
 * Return: Nothin
 */
void create_fork(char **cmd, char *name, char **envp, int circl)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(cmd);
	}
	else if (pid == 0)
	{
		execute(cmd, name, envp, circl);
		free_par(cmd);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(cmd);
		}
		free_par(cmd);
	}
}


/**
  * _cd - Afunction that changes working directo
  * @path: The new current working director
  * Return: 0 on succes
  */
int _cd(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) != 0)
	{
		perror(path);
		return (98);
	}
	return (1);
}
