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
/**
* main - A function that runs our shell.
* @ac: The number of inputed arguments.
* @av: The pointer to array of inputed arguments.
* @envp: The pointer to array of enviromental variables.
* Return: Always 0.
*/

int main(int ac, char **av, char **envp)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_read = 0;
	int cicles = 0;
	(void)ac;

	while (1)
	{
		cicles++;
		display_prompt();
		signal(SIGINT, handle);
		chars_read = getline(&buffer, &buf_size, stdin);
		if (chars_read == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokening(buffer, " \0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				shell_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				change_dir(command[1]);
			else
				create_fork(command, av[0], envp, cicles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

