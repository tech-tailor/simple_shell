#include "simple_shell.h"

/**
 * display_prompt - display the prompt
 * Return: Nothing
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * _EOF - A function that verigy if we reach at the end
 * @buffer: The pointer to the input string
 * Return: Nothing
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
 * print_error - A function that prints error msg
 * @name: The name of the shell
 * @cicl: times does  the chell executed
 * @commands: The pointer to tokeniz command
 * Return: Nothing
 */
void print_error(char *name, int cicl, char **commands)
{
	char c;

	c = cicles + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, commands[0], _strlen(commands[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * handle - A function to handle Ctr + C
 * @signals: The signal to handle
 * Return: Nothing
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n$ ", 3);
}
