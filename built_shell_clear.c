#include "shell.h"

/**
 * shell_clear - clears the terminal screen.
 * @args: an array of arguments
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
 */

int shell_clear(char **args)
{
/* avoid "unused parameter" warning */
(void)args;
printf("\033[2J\033[H");
/* Ensure flushed Output */
fflush(stdout);
return 1;
}
