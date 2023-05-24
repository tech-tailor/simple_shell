#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

 void read_data(char *comd, char **par);
 void read_data1(char *comd, char **par);
 void display_prompt();
 void display_promptt();
 int main(int argc, char **argv, char **envp);
 ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
 char *_strcpy(char *destination, const char *source);






#endif
