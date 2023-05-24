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
		return (0);

	while (1)
	{
		display_prompt();
		read_data(command, parameters);
		if (fork() != 0)
			wait(NULL);
		else
		{
			strcpy(cmd, "/bin/");
			printf("value is %s \n", command);
			if (command == NULL)
			{
				printf("Nill \n");
				continue;
			}
			strcat(cmd, command);
			execve(cmd, parameters, envp);
			if (strcmp(command, "exit") == 0)
				break;
			perror(argv[0]);
		}
		if (strcmp(command, "exit") == 0)
			break;
	}
	return (1);
}
