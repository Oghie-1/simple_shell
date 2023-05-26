#include "shell.h"

/**
 * shell_cd - changes the current working directory of the shell
 * @args: array of arguments
 *
 */

void shell_cd(char **args)
{
char *dir = args[1];
int ret;

/* If no argument is provided, change to HOME directory */
if (dir == NULL)
{
/* Assuming you have implemented this function */
dir = get_environment_variable("HOME");
if (dir == NULL)
{
/* Assuming you have implemented this function */
print_error_message("cd: No HOME directory found");
return;
}
}

ret = chdir(dir);
if (ret == -1)
{
perror("cd");
}
}
