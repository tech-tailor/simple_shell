#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


void read_data(char *comd, char **par);
void read_data1(char *comd, char **par);
void display_prompt(void);
void display_promptt(void);
int main(int argc, char **argv, char **envp);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strcpy(char *destination, const char *source);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *destination, const char *source);


void read_data(char *comd, char **par);
void display_prompt(void);
int main(int argc, char **argv, char **envp);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);




#endif
