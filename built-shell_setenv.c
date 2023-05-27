#include "shell.h"

/**
 * set_environment_variable - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 *
 * Return: 0 on success, -1 on failure
 */

int set_environment_variable(char **args)
{
if (args[1] == NULL || args[2] == NULL)
{
print_error_message("Usage: setenv VARIABLE VALUE\n");
return -1;
}

if (set_environment_variable(args) != 0)
{
print_error_message("setenv");
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
if (args[1] == NULL)
{
print_error_message("Usage: unsetenv VARIABLE\n");
return -1;
}

if (unset_environment_variable(&args[1]) != 0)
{
print_error_message("unsetenv");
return -1;
}
return 0;
}
