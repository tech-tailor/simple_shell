#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

void execute(char **command, char *name, char **env);
void _fork(char **command, char *name, char **env);
void read_data(char **par);
void display_prompt(void);
int main(int argc, char **argv, char **envp);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strcpy(char *destination, const char *source);
int _strcmp(const char *s1, const char *s2);
unsigned int _strlen(char *s);
char *_strcat(char *destination, const char *source);
int _atoi(char *s);
void free_par(char **cmd);
void free_exit(char **cmd);
void handle(int signals);
char **_getPATH(char **env);
void shell_exit(char **command);
char **_getPATH(char **env);
void print_env(char **env);
int change_dir(const char *path);
char **tokening(char *buffer, const char *s);



#endif
