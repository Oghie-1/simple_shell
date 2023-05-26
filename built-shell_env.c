#include "shell.h"

/**
 * display_environment - Prints all the environment variables.
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
 */
int display_environment(void)
{
int i;

for (i = 0; environ[i]; i++)
{
printf("%s\n", environ[i]);
}

return 1;
}
