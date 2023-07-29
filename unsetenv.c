#include "shell.h"

/**
 * shell_unsetenv - Unset an environment variable
 * @args: The name of the environment variable to unset
 * Return: 0 on success, 1 on failure
 */

/* Function to unset an environment variable */
int shell_unsetenv(char *args[]) {
if (args[1]==NULL) {
fprintf(stderr, "Usage: unsetenv VARIABLE\n");
return 1;
}

if (unsetenv(args[1]) !=0) {
perror("Error: unsetenv");
return 1;
}
return 0;
}
