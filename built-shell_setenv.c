#include "shell.h"

/**
 * set_environment_variable - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 *
 * Return: 0 on success, -1 on failure
 */

int set_environment_variable(char **args)
{
char *name, *value;

if (args[1] == NULL || args[2] == NULL)
{
print_error_message("Usage: setenv VARIABLE VALUE\n");
return -1;
}

name = args[1];
value = args[2];

if (set_environment_variable(name, value, 1) != 0)
{
print_error-message("setenv");
return -1;
}
return 0;
}

/**
 * shell_unsetenv - Unset an environment variable
 * @args: Arguments (name of the environment variable)
 *
 * Return: 0 on success, -1 on failure
 */

int unset_environment_variable(char **args)
{
char *name;

if (args[1] == NULL)
{
print_error_message("Usage: unsetenv VARIABLE\n");
return -1;
}

name = args[1];

if (unset_environment_variable(name) != 0)
{
print_error_message("unsetenv");
return -1;
}
return 0;
}
