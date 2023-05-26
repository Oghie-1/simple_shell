#include "shell.h"

/**
 * shell_setenv - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 *
 * Return: 0 on success, -1 on failure
 */

int shell_setenv(char **args)
{
char *name, *value;

if (args[1] == NULL || args[2] == NULL)
{
print_error_message("Usage: setenv VARIABLE VALUE\n");
return -1;
}

name = args[1];
value = args[2];

if (setenv(name, value, 1) != 0)
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

int shell_unsetenv(char **args)
{
char *name;

if (args[1] == NULL)
{
print_error_message("Usage: unsetenv VARIABLE\n");
return -1;
}

name = args[1];

if (unsetenv(name) != 0)
{
print_error_message("unsetenv");
return -1;
}
return 0;
}
