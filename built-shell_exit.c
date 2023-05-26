#include "shell.h"

/**
 * shell_exit - Exit the shell.
 * @args: Arguments.
 *
 * Return: void.
 */

void exit_shell(char **args)
{
int status = 0;

if (args[1] != NULL)
{
status = _atoi(args[1]);
}

free_token_array(args);
free_last_input();
exit(status);
}
