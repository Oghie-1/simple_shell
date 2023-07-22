#ifndef SHELL_H
#define SHELL_H

#define MAX_NUM_ARGS 10

/* Standard Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

/*Prototypes */
void parse_command(char *command, char *args[]);
void execute_command(char *args[]);
void display_prompt();
char *read_command();
void handle_sigint(int sig);

extern char **environ;
char *program_name;


#if 1

char *shell;
int line_number;

#endif

#endif /* #ifndef SHELL_H */

