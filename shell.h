#ifndef SHELL_H
#define SHELL_H

#define MAX_NUM_ARGS 10
#define MAX_ALIASES 50

/* Standard Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
char *name;
char *value;
} Alias;

/* Function Prototypes */
void parse_command(char *command, char *args[]);
void execute_command(char *args[]);
void displayShellPrompt(void);
/* Function to set a new environment variable or modify an existing one */
int shell_setenv(char *args[]);

/* Function to unset an environment variable */
int shell_unsetenv(char *args[]);


/*alias type*/
void alias_builtin(char *args[], Alias aliases[]);

/* function  for the cd_builtin command */
void cd_builtin(char *args[]);


/* Declare the environ variable */
extern char **environ;

#if 1
char *shellName; /* Variable to hold the name of the shell program */
int lineNumber; /* Variable to keep track of the line number in the shell */
#endif

#endif /* #ifndef SHELL_H */

