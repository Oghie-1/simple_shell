#include "shell.h"

/**
 * execute_command - forks and executes commands
 * @args: pointer to arguments
 */

#include "shell.h"

ExecutionResult execute_command(char *args[])
{
int status;
pid_t pid;

/* Increment line_number */
++line_number;

pid = fork();
if (pid == 0)
{
    // Child process

    // Execute the command
    execvp(args[0], args);

    // If execvp returns, it means the command execution failed
    // Print an error message and exit with a non-zero status
    fprintf(stderr, "%s: %d: %s: not found\n", program_name, line_number, args[0]);
    exit(EXIT_FAILURE);
}
else if (pid > 0)
{
    // Parent process

    // Wait for the child process to complete
    if (waitpid(pid, &status, 0) == -1)
    {
        perror("Error: waitpid");
        return EXECUTION_FAILURE;
    }

    // Check if the child process terminated normally
    if (WIFEXITED(status))
    {
        // Check the exit status of the child process
        int exit_status = WEXITSTATUS(status);

        if (exit_status == 0)
        {
            return EXECUTION_SUCCESS;
        }
        else
        {
            // Command executed but returned non-zero status
            return EXECUTION_FAILURE;
        }
    }
    else if (WIFSIGNALED(status))
    {
        // The child process was terminated by a signal
        fprintf(stderr, "%s: %d: %s terminated by signal %d\n", program_name, line_number, args[0], WTERMSIG(status));
        return EXECUTION_FAILURE;
    }
    else
    {
        // Some other error in the child process
        fprintf(stderr, "Error: child process did not terminate normally\n");
        return EXECUTION_FAILURE;
    }
}
else
{
    // Fork failed
    perror("Error: failed to fork\n");
    return FORK_FAILURE;
}
}

void execute_command(char *args[])

{
int status;
pid_t pid;

#if 0

char cmd[100], shell[100];

#endif

#if 0
FILE *fp;

snprintf(cmd, sizeof(cmd), "ps -p %d -o comm=", ppid);
fp = popen(cmd, "r");
if (fp == NULL)
perror("Failed to execute command\n");
if (fgets(shell, sizeof(shell), fp) == NULL)
perror("Failed to read output\n");
pclose(fp);

#endif

#if 1

++line_number;

#endif

pid = fork();
if (pid == 0)
{
execvp(args[0], args);
#if 0
    
printf("%s: %d: %s: not found\n", shell, __LINE__, args[0]);

#else

printf("%s: %d: %s: not found\n", shell, line_number, args[0]);

#endif

exit(1);
}
else if (pid > 0)
{
wait(&status);
}
else
{
perror("Error: failed to fork\n");
exit(1);
}
}

