#ifndef SHELL_H
#define SHELL_H

#define MAX_NUM_ARGS 10

/* Standard Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Function Prototypes */
void parse_command(char *command, char *args[]);
void execute_command(char *args[]);
void displayShellPrompt(void);

#if 1
char *shellName; /* Variable to hold the name of the shell program */
int lineNumber; /* Variable to keep track of the line number in the shell */
#endif

#endif /* #ifndef SHELL_H */

