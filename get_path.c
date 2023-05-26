#include "shell.h"

/**
 * get_path - Returns the value of the PATH environment variable.
 *
 * Return: Pointer to the value of PATH, or NULL if it doesn't exist.
 */
char *get_path(void)
{
return _getenv("PATH");
}
