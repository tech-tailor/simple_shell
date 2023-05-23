#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

 void read_from_termnal(char *comd, char **par);
 void display_prompt();
 int main(int argc, char **argv, char);
 void handle_path(char *cmd, char **par);





#endif
