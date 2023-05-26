#include "simple_shell.h"

/**
<<<<<<< HEAD
 * execute - A function that executes a command.
 * @command: The pointer to tokienized command
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @cicles: Number of executed cicles.
 * Return: Nothing.
 */
void execute(char **command, char *name, char **env, int cicles)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
=======
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
>>>>>>> e878228c25b1859e05f7cb4d21d46a81cc50d51e
		}
	}
	else
	{
<<<<<<< HEAD
		pathways = _getPATH(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					free_dp(pathways);
					free_exit(command);
=======
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
>>>>>>> e878228c25b1859e05f7cb4d21d46a81cc50d51e
				}
				return;
			}
		}
<<<<<<< HEAD
		msgerror(name, cicles, command);
		free_dp(pathways);
	}
}


/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
=======
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
>>>>>>> e878228c25b1859e05f7cb4d21d46a81cc50d51e
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
<<<<<<< HEAD


/**
 * _getPATH - A function to gets the full value from.
 * enviromental variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All tokenized pathways for commands.
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
 * msgerror - A function that prints message not found.
 * @name: The name of the shell.
 * @cicles: Number of cicles.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void msgerror(char *name, int cicles, char **command)
{
	char c;

	c = cicles + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
=======
>>>>>>> e878228c25b1859e05f7cb4d21d46a81cc50d51e
