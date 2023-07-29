#include "shell.h"

/**
 * cd_builtin - Change the current directory of the process
 * @args: Pointer to the array of arguments for the cd command
 */
void cd_builtin(char *args[])
{
char *directory;
char cwd[1024];

/* If no argument is given to cd, change to $HOME */
if (args[1] == NULL)
{
directory = getenv("HOME");
if (directory == NULL)
{
fprintf(stderr, "Error: $HOME not set\n");
return;
}
}
else if (strcmp(args[1], "-") == 0)
{
/* Handle the "cd -" command to change to the previous directory */
directory = getenv("OLDPWD");
if (directory == NULL)
{
fprintf(stderr, "Error: OLDPWD not set\n");
return;
}
printf("%s\n", directory);
}
else
{
/* Change to the specified directory */
directory = args[1];
}

/* Change the current directory and update PWD and OLDPWD */
if (chdir(directory) == -1)
{
perror("cd");
return;
}

if (getcwd(cwd, sizeof(cwd)) != NULL)
{
setenv("PWD", cwd, 1);
setenv("OLDPWD", directory, 1);
}
else
{
perror("getcwd");
}
}
