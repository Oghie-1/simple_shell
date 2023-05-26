#include "shell.h"

/**
 * free_error_arguments - Frees allocated pointers following a system error.
 * @argv: Pointer to an array of pointers.
 * @arg: Pointer to an array of characters.
 *
 * Return: void.
 */

void free_error_arguments(char **argv, char *arg)
{
int i;

for (i = 0; argv[i]; i++)
free(argv[i]);
free(argv);
free(arg);
exit(EXIT_FAILURE);
}

/**
 * free_token_array - Frees memory allocated dynamically by tokenize().
 * @ptr: Pointer to the allocated memory.
 *
 * Return: void.
 */
void free_token_array(char **tokens)
{
int i;

for (i = 0; tokens[i]; i++)
free(tokens[i]);
free(tokens);
}

/**
 * free_path_variable - Frees global variable
 *
 * Return: void.
 */
void free_path_variable(void)
{
if (environ != NULL)
{
size_t i = 0;

while (environ[i] != NULL)
{
if (_strncmp(environ[i], "PATH=", 5) == 0)
{
free(environ[i]);
environ[i] = NULL;
break;
}
i++;
}
}
}
