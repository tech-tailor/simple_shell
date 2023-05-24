#include "simple_shell.h"

/**
 * main - The entry function of our program
 * @argc: number of arguments
 * @envp: viarable to the outside env
 * @argv: arguments
 * Return: void
 */
int main(int argc, char **argv, char **envp)
{
	char cmd[100], command[50], *parameters[10];

	if (argc < 0)
		return (1);

	while (1)
	{
		display_prompt();
		read_data(command, parameters);
		if (fork() != 0)
			wait(NULL);
		else
		{
			if (_strcmp(command, "/bin/ls") != 0)
				_strcpy(cmd, "/bin/");
			_strcat(cmd, command);
			execve(cmd, parameters, envp);
			if (_strcmp(command, "exit") == 0)
				break;
			perror(argv[0]);
		}
		if (_strcmp(command, "exit") == 0)
			break;
	}
	return (1);
}
