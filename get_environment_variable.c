#include "shell.h"

/**
 * *get_environment_variable - Get the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */

char *get_environment_variable(const char *name)
{
char **env;
size_t name_len = _strlen(name);

for (env = environ; *env != NULL; env++)
{
if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
{
return &((*env)[name_len + 1]);
}
}
return NULL;
}
