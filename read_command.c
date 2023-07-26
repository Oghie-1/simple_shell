#include "shell.h"

ExecutionResult execute_command(char *args[])
{
int status;
pid_t pid;
++line_number;

pid = fork();
if (pid == 0)
{
// Child process
// Free dynamically allocated memory before calling execvp
free_memory(args);

// Null-terminate the args array
args[MAX_NUM_ARGS] = NULL;

execvp(args[0], args);

// If execvp returns, there was an error
handle_error("Command not found");

// ExecutionResult is used to report errors to the caller
return COMMAND_NOT_FOUND;
}
else if (pid > 0)
{
// Parent process
wait(&status);
// Check the exit status of the child process
if (WIFEXITED(status))
{
    int exit_code = WEXITSTATUS(status);
    if (exit_code == 0)
    {
        // Execution success
        return EXECUTION_SUCCESS;
    }
    else
    {
        // Execution failure with non-zero exit code
        return EXECUTION_FAILURE;
    }
}
else
{
    // Execution failure due to abnormal child termination
    return EXECUTION_FAILURE;
}
}
else
{
// Fork failure
handle_error("Failed to fork");
return FORK_FAILURE;
}
}

char *read_command()
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters = getline(&buffer, &bufsize, stdin);

if (characters == -1)
{
if (feof(stdin))
{
/* Handle EOF (Ctrl+D) */
printf("\nReceived EOF (Ctrl+D). Exiting the shell.\n");
}
else
{
/* Handle other errors during input reading */
perror("Error: getline() failed\n");
}

/* Return NULL to indicate no command was read */
return NULL;
}

/* Remove the trailing newline character at the end of the command */
buffer[strcspn(buffer, "\n")] = '\0';

/* Check for an empty command (only whitespace characters) */
char *temp = buffer;
while (*temp != '\0')
{
if (!isspace(*temp))
{
/* Non-empty command, return the buffer */
return buffer;
}
temp++;
}

/* Free memory if the command is empty (only whitespace characters) */
free(buffer);

/* Return NULL to indicate no command was read */
return NULL;
}
