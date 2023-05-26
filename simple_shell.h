#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int ac, char **av, char **env);
void display_prompt(void);
void handle(int signals);
void _EOF(char *buffer);
void shell_exit(char **command);


void create_fork(char **command, char *name, char **env, int cicles);
int change_dir(const char *path);


void execute(char **commands, char *name, char **envp, int cicl);
void print_env(char **env);
char **_getPATH(char **env);
void print_error(char *name, int cicl, char **commands);


char **tokening(char *buffer, const char *s);


void free_par(char **command);
void free_exit(char **command);


int _strcmp(const char *s1, const char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *destination, const char *source);
int _atoi(char *s);
char *_strcat(char *dest, const char *src);


#endif
