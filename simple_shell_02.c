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
	char cmd[50], command[50], *parameters[10];
	char *envp[] = {(char *)"PATH=/bin", 0};

	while (1)
	{
		display_prompt();
		read_from_terminal(command, parameters);

		if (fork() != 0)
			wait(NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
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
	char *line = NULL,  *token;
	int i = 0;
	size_t buffsize = 0;
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
		if (i == 0)
		{
			strcpy(cmd, token);
		}
		par[i] = token;
		i++;
		token = strtok(NULL, " \n");

	}
	par[i] = NULL;
}