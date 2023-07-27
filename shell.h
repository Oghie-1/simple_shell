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
#include <ctype.h>

/* Error Codes */
typedef enum
{
EXECUTION_SUCCESS,
EXECUTION_FAILURE,
FORK_FAILURE,
COMMAND_NOT_FOUND
} ExecutionResult;

/*Prototypes */
void parse_command(char *command, char *args[]);
void display_prompt();
char *read_command();
void handle_sigint(int sig);
ExecutionResult execute_command(char *args[]);

/*Function to set up signal handlers */
void setup_signal_handlers();

/* Error handling function */
void handle_error(const char *message);

/* Memory freeing function */
void free_memory(char *args[]);

extern char **environ;
char *program_name;

/* Function to handle errors and exit */
void handle_error(const char *message)
{
fprintf(stderr, "Error: %s\n", message);
exit(EXIT_FAILURE);
}

/* Function to free allocated memory in args[] */
void free_memory(char *args[])
{
for (int i = 0; args[i] != NULL; i++)
{
free(args[i]);
args[i] = NULL;
}
}


#if 1

char *shell;
int line_number;

#endif

#endif /* #ifndef SHELL_H */

