#include "simple_shell.h"

void read_from_terminal(char *comd, char **par);
void display_prompt();
/**
 * main - Entry program
 * @agrc: - the number of arguments
 * @argv: - arguments
 * Return: 0 Always
 */
int min(int argc, char** argv, char** envp)
{
	char cmd[50], command[50], *parameters[10];

	if (argc < 1)
		return (1);
	while (1)
	{
		display_promptt();
		read_data1(command, parameters);

		if (fork() != 0)
			wait(NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parameters, envp);
			perror(argv[0]);
		}
	}
	return (1);
}

/**
 * display_prompt - display the prompt
 * Return: Nothing
 */
void display_promptt()
{
	static unsigned int is_first_time = 1;

	while (is_first_time)
	{
		is_first_time = 0;
	}
	printf("$ ");
}

/**
 * read_from_terminal - the function that get command from terminal
 * @cmd: The first argument
 * @par: Here 
 */
void read_data1(char *cmd, char **par)
{
	char *line = NULL, *arr[10], *token;
	size_t i = 0, j = 0, buffsize = 0;
	ssize_t len = -1;

	while (len == -1)
	{
		len = _getline(&line, &buffsize, stdin);
	}
	if (len == 0)
		return;
	token = strtok(line, " \n");

	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n");
	}
	strcpy(cmd, arr[0]);

	for (j = 0; j < i; j++)
		par[j] = arr[j];
	par[i] = NULL;
}
