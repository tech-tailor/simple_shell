#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

<<<<<<< HEAD
 void read_from_termnal(char *comd, char **par);
=======
 void read_data(char *comd, char **par);
>>>>>>> 18978fac0f8c18af1dac9a5aa2e4562235bf5afc
 void display_prompt();
 int main(int argc, char **argv, char);
 void handle_path(char *cmd, char **par);





#endif
