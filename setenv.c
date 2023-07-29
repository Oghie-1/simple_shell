
#include "shell.h"

/**
 * shell_setenv - Set a new environment variable or modify an existing one
 * @args: The name of the environment variable
 *
 * Return: 0 on success, 1 on failure
 */

/* Function to set a new environment variable or modify an existing one */
int shell_setenv(char *args[])
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
return 1;
}

if (setenv(args[1], args[2], 1) != 0)
{
perror("Error: setenv");
return 1;
}

return 0;
}


