#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av, char **envp);
void display_prompt(void);
void handle(int signals);
void _EOF(char *buffer);
int _cd(char *path);
void shell_exit(char **cmd);
void execute(char **cmd, char *name, char **envp, int circl);
void print_envp(char **envp);
char **_getPATH(char **envp);
void print_error(char *name, int circl, char **cmd);
void create_fork(char **cmd, char *name, char **envp, int circl);
char **_strtok(char *buffer, const char *s);
char *_strcpy(char *dest, char *src);
void free_par(char **cmd);
void free_exit(char **cmd);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

#endif
