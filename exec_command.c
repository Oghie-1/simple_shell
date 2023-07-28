#include "shell.h"

/**
 * execute_command - Forks and executes commands
 * @args: Pointer to the array of arguments for the command
 */
void execute_command(char *args[])
{
int status;
pid_t pid;

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

