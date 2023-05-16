#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void read_from_terminal(char *comd, char **par);
void display_prompt();
/**
 * main - Entry program
 * @agrc: - the number of arguments
 * @argv: - arguments
 * Return: 0 Always
 */
int main()
{
	char *cmd, command[50], *parameters[10];
	char *envp[] = {(char *)"PATH=/bin", 0};

	if (!isatty(STDIN_FILENO))
	{
		execle("/bin/ls", "/bin/ls", NULL, envp);
		return (0);
	}
	while (1)
	{
		display_prompt();
		read_from_terminal(command, parameters);

		if (fork() != 0)
			wait(NULL);
		else
		{
			cmd = command;
			execve(cmd, parameters, envp);
			perror("./shell");
		}
	}
	return (1);
}

/**
 * display_prompt - display the prompt
 * Return: Nothing
 */
void display_prompt()
{
	static unsigned int is_first_time = 1;

	while (is_first_time)
	{
		is_first_time = 0;
	}
	printf("#cisfun$ ");
}

/**
 * read_from_terminal - the function that get command from terminal
 * @cmd: The first argument
 * @par: Here 
 */
void read_from_terminal(char *cmd, char **par)
{
	char *line = NULL, *arr[10], *token;
	size_t i = 0, j = 0, buffsize = 0;
	ssize_t len = -1;

	while (len == -1)
	{
		len = getline(&line, &buffsize, stdin);
	}
	if (len == 0)
		return;
	token = strtok(line, " \n");

	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n");
	}
	if (i > 1)
	{
		strcpy(cmd, "yes");
		return;
	}
	strcpy(cmd, arr[0]);

	par[j] = arr[j];
	par[i] = NULL;
}
