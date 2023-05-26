#include "shell.h"

/**
 * shell_env - Prints all the environment variables.
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
 */
int shell_env(void)
{
int i;

for (i = 0; environ[i]; i++)
{
printf("%s\n", environ[i]);
}

return 1;
}
