#include "simple_shell.h"

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
prompt();
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
create_child(command, av[0], envp, cicles);
}
fflush(stdin);
buffer = NULL, buf_size = 0;
}
if (chars_read == -1)
return (EXIT_FAILURE);
return (EXIT_SUCCESS);
}

