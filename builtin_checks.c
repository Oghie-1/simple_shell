#include "shell.h"

/**
 * check_for_builtin - checks if the command is a built-in function
 * @args: the arguments array
 *
 * Return: 1 if the command is a built-in function, 0 otherwise
 */
int check_for_builtin(char **args)
{
/* If no command is provided */
if (!args[0])
return (0);
/* If command is "exit" */
if (!_strcmp(args[0], "exit"))
/* Call shell_exit function */
exit_shell(args);
/* If command is "env" */
else if (!_strcmp(args[0], "env"))
/* Call shell_env function */
set_environment_variable();
/* If command is "setenv" */
else if (!_strcmp(args[0], "setenv"))
/* Call shell_setenv function */
shell_setenv(args);
/* If command is "unsetenv" */
else if (!_strcmp(args[0], "unsetenv"))
/* Call shell_unsetenv function */
shell_unsetenv(args);
/* If command is "help" */
else if (!_strcmp(args[0], "help"))
/* Call shell_help function */
show_help();
/* If command is "cd" */
else if (!_strcmp(args[0], "cd"))
/* Call shell_cd function */	
change_directory(args);
/* If command is "clear" */
else if (!_strcmp(args[0], "clear"))
/* Call shell_clear function */
clear_screen(args);
else
/* Command is not a built-in function */
return (0);
/* Command is a built-in function */
return (1);
}
