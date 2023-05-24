#include "shell.h"

/**
 * stress - Exits main function, produces appropriate error messages,
 *        prints environment, checks if command is executable, forks and executes.
 *
 * @array: Array of pointers to command line tokens.
 * @argv: Current command line arguments.
 * @env: Array of environmental variables.
 * @p_t: Array of pointers to tokenized path.
 * @i: Number of calls.
 * @e_c: Exit integer value.
 *
 * Return: 1 on failure, 0 on success.
 */

int stress(char **array, char **argv, char **env, char **p_t, int i, int *e_c)
{
int error = 0;
char *ptr = NULL, *a_call_count = NULL;

if (array != NULL && !(_strcmp(array[0], "exit"))) /* If command is "exit" */
{
if (array[1] == NULL)
return (1);

*e_c = _atoi(&error, array[1]); /*convert second arg to integer */

if (error)
{
a_call_count = _intstr(i);
ERR_EXIT(argv[0], a_call_count, array[1]); /* Print error message*/
free(a_call_count);
}
else
return (1);
}
else if (array != NULL && !(_strcmp(array[0], "env"))) /*If command is "env" */
{
print_env(env); /* Print env var*/
}
else if (array != NULL && access(array[0], F_OK) == -1) /* If command is not executable*/
{
ptr = array[0];
array[0] = auto_cat(p_t, array[0]); /*Concatenate command with path */

if (array[0] == NULL)
{
array[0] = _strdup("(nil)");
a_call_count = _intstr(i);
ERR_EXE(argv[0], a_call_count, ptr); /* Print error message */
free(a_call_count);
}

free(ptr);
}

if (array != NULL && _strcmp(array[0], "(nil)")) /* If command is not "(nil)" */
fork_help(array); /* Fork and execute command*/

return (0);
}

