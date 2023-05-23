#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char** environ;
void display_prompt();
void read_data(char*, char**);
/**
 * main - The entry function of our program
 * @argc: number of arguments
 * @argv: arguments
 * Return: Nothing
 */
int main(int argc, char **argv)
{
	char cmd[100], command[50], *parameters[10];

	if (argc < 0)
		return (0);

	while(1)
	{
		display_prompt();
		read_data(command, parameters);
		if (fork() != 0)
			wait(NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parameters, environ);
			if (strcmp(command, "exit")== 0)
				break;
			perror(argv[0]);
		}
		if (strcmp(command, "exit")== 0)
			break;
	}
	return (1);
}

/**
 * display_prompt - display new terminal
 *
 * Return: Nothing
 */
void display_prompt()
{
	static int at_first_time = 1;

	while(at_first_time)
		at_first_time = 0;
	printf("$ ");
}

/**
 * read_data - read data from terminal
 * @cmd: first command
 * @par: other parameters
 * Return: inputed data
 */
void read_data(char *cmd, char **par)
{
	size_t i = 0, j = 0, buffsize = 0;
	ssize_t len = 0;
	char *line = NULL, *arr[10], *token;

	len = getline(&line, &buffsize, stdin);
	if (len < 1)
	{
		if (len == 0)
			free(line);
		return;
	}
	fflush(stdin);

	token = strtok(line, " \n");

	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, " \n");
	}
	if (i == 0)
	{
		free(line);
		return;
	}
	strcpy(cmd, arr[0]);
	for (;j < i; j++)
		par[j] = arr[j];
	par[i] = NULL;
	free(line);
}
