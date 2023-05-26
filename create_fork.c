#include "simple_shell.h"

/**
* create_fork - A function that creates a sub process.
* @command: The pointer to tokenized command
* @name: The pointer to the name of shell.
* @envp: The pointer to the enviromental variables.
* @cicles: Number of executed cicles.
* Return: Nothing.
*/
void create_fork(char **command, char *name, char **envp, int cicles)
{
int pid = 0;
int status = 0;
int wait_error = 0;

pid = fork();
if (pid < 0)
{
perror("Error: ");
free_exit(command);
}
else if (pid == 0)
{
execute(command, name, envp, cicles);
free_par(command);
}
else
{
wait_error = waitpid(pid, &status, 0);
if (wait_error < 0)
{
free_exit(command);
}
free_par(command);
}
}
