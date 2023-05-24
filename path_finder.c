#include "shell.h"

/**
 * path_finder - find the PATH variable in environment list
 *
 * @var: string literal of desired environmental variable
 * @env: environment list
 * Return: string of desired environment variable and its value
 */

char *path_finder(const char *var, char **env)
{
int i = 0, ii = 0;

if (!(var) || !(env))
return (NULL);

while (env[ii] != NULL)
{
i = 0;

/* Compare each character of the desired variable with the environment variable */
while (var[i] != '\0' && var[i] == env[ii][i])
i++;

/* Check if the desired variable is found */
if (var[i] == '\0')
return (env[ii]);

ii++; /* Move to the next environment variable */
}

return (NULL); /* Return NULL if the desired variable is not found */
}
