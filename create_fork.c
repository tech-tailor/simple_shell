#include "simple_shell.h"
/**
 * create_fork - it creates sub process
 * @cmd: pointer to tokenied cmd
 * @name: pointer to the nm f shell.
 * @envp: pointer to the eniomental variables.
 * @circl: executed cic no
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
_exit(0);
}
else
{
wait_error = waitpid(pid, &status, 0);
if (wait_error < 0)
free_exit(cmd);

free_par(cmd);
}
}

/**
  * _cd - Afunction that changes working directo
  * @path: The new current working director
  * Return: 0 on succes
  */
int _cd(char *path)
{
	char curr_dir[1024];

	if (path == NULL)
	{
		if (getenv("HOME") == NULL)
			path = getcwd(curr_dir, 1024);
		else
			path = getenv("HOME");
	}

	if (_strcmp(path, "-") != 0)
	{
		if (getenv("OLDPWD") == NULL)
			path = getcwd(curr_dir, 1024);
		else
			path = getenv("OLDPWD");
	}

	if (getcwd(curr_dir, 1024) == NULL)
	{
		perror(path);
		return (98);
	}
	if (chdir(path) != 0)
	{
		perror(path);
		return (98);
	}
	setenv("PWD", path, 1);
	setenv("OLDPWD", curr_dir, 1);
	return (1);
}

/**
 * shell_setenv - set the enviroment variable
 * @variable: name of the enviroment var
 * @value: new value
 * Return: 0 on succes
 */

int shell_setenv(const char *variable, const char *value)
{
if (setenv(variable, value, 1) != 0)
{
write(STDERR_FILENO, "setenv: Failed to set environment variable\n", 43);
return (0);
}
return (1);
}

/**
* shell_unsetenv - unset the enviroment variable
* @variable: name of the enviroment var
* Return: 0 on succes
*/

int shell_unsetenv(const char *variable)
{
if (unsetenv(variable) != 0)
{
write(STDERR_FILENO, "unsetenv: Failed to unset environment variable\n", 47);
return (0);
}
return (1);
}
