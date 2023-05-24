#include "shell.h"

/**
 * shell_run - check if getline fails
 *
 * @go: return value of getline function
 * Return: 1 on failure, 0 on success
 */
int shell_run(int go)
{
if (go == -1)
{
write(STDIN_FILENO, "\n", 1); /* Print a newline character */
return (1); /* Return 1 indicating failure */
}

return (0); /* Return 0 indicating success */
}

