#include "shell.h"

/**
 * execute_command - Forks and executes commands
 * @args: Pointer to the array of arguments for the command
 */
void execute_command(char *args[])
{
extern char **environ;
int status;
pid_t pid;

if (args[0] == NULL)
{
/* eMPTY COMMAND, DO NOThing*/

return;
}

/* Handle the "exit" command*/

if (strcmp(args[0], "exit") == 0)
{
int exit_status = 0;

/* Check if there'' an argument provided after exit*/
if (args[1] != NULL)
{
/*Convert the argument to an integer */
exit_status = atoi(args[1]);
}

/*exit the shell with the specified status  */
exit(exit_status);
}

/* Handle the "env" command */
if (strcmp(args[0], "env") == 0)
{
/* Print the current environment variables */
char *env_var = *environ; /* Get the first environment variable */
while (env_var != NULL)
{
printf("%s\n", env_var); /* Print each environment variable */
env_var = *(environ++); /* Move to the next environment variable */
}
return;
}

/* Handle the "setenv" command */
if (strcmp(args[0], "setenv") == 0)
{
if (shell_setenv(args) != 0)
{
fprintf(stderr, "Error: Failed to set environment variable\n");
}
return;
}

/* Handle the "unsetenv" command */
if (strcmp(args[0], "unsetenv") == 0)
{
if (shell_unsetenv(args) != 0)
{
fprintf(stderr, "Error: Failed to unset environment variable\n");
}
return;
}

/* execute other non-built-in commands using fork and execvp as before */

pid = fork();
if (pid == 0)
{
/* Child process */
execvp(args[0], args);

/* If the command execution fails, print an error message and exit with status 1 */
printf("Error: Command not found - %s\n", args[0]);
exit(1);
}
else if (pid > 0)
{
/* Parent process */
wait(&status); /* Wait for the child process to complete */
}
else
{
/* Forking failed */
perror("Error: Failed to fork\n");
exit(1);
}
}

