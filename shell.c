#include "shell.h"

/**
 * main - Main shell program
 * @argc: Number of arguments (unused)
 * @argv: Array of command-line arguments (unused)
 * Return: 0.
 */
int main(int argc, char **argv)
{
char *command = NULL;
size_t n = 0;
char *args[MAX_NUM_ARGS + 1];

#if 1
shellName = *argv; /* Save the shell program name */
#endif

(void)argc; /* Suppress unused parameter warning */

/* Check if the shell is run in non-interactive mode */
if (!isatty(STDIN_FILENO))
{
if (getline(&command, &n, stdin) == -1)
{
perror("Error: getline() failed\n");
return 1;
}
command[strcspn(command, "\n")] = '\0'; /* Remove the newline character from the command */
parse_command(command, args); /* Parse the command into arguments */
execute_command(args); /* Execute the parsed command */
free(command);
return 0;
}

/* Interactive mode */
while (1)
{
displayShellPrompt(); /* Display the shell prompt (username@cwd$) */
if (getline(&command, &n, stdin) == -1)
{
perror("Error: getline() failed\n");
break;
}
command[strcspn(command, "\n")] = '\0'; /* Remove the newline character from the command */
parse_command(command, args); /* Parse the command into arguments */

/* Check if the user wants to exit the shell */
if (strcmp(args[0], "exit") == 0)
{
break;
}

execute_command(args); /* Execute the parsed command */
}

free(command);
return 0;
}

