#include "simple_shell.h"

/**
 * main - A function fo shell
 * @ac: arguments cout
 * @av: arguments vecr
 * @envpp: envpiromenl variables pointer
 * Return: Always0
 */
int main(int ac, char **av, char **envpp)
{
	char *buffer = NULL, **cmd = NULL;
	size_t buf_size = 0;
	ssize_t chars_read = 0;
	int circl = 0;
	(void)ac;

	while (1)
	{
		circl++;
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
			cmd = _strtok(buffer, " \0");
			if (cmd == NULL)
			{
				free(buffer);
				continue;
			}
			free(buffer);
			check(cmd, av, envpp, &circl);
		}

		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * display_prompt - display_prompt function
 * Return: void
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}


/**
 * handle - to handle Ct + C signal
 * @signals: The sgnal to hadle
 * Return: Nothing.
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * _EOF - A function that chaecks if buffer is EOF
 * @buffer: Theonter to the input string
 * Return: Nothin
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}


/**
 * shell_exit - Afnction that exits the shell
 * @cmd: The pointer to tkenized cmd
 * Return: Nothig
 */
void shell_exit(char **cmd)
{
	int sta_tus = 2;

	if (cmd[1] == NULL)
	{
		free_par(cmd);
		exit(EXIT_SUCCESS);
	}
	sta_tus = _atoi(cmd[1]);
	free_par(cmd);
	exit(sta_tus);
}
