#include "shell.h"

/**
 * _strlen - Measures the length of a string.
 *
 * @s: Passed string.
 * Return: Length of string.
 *
 *
 */

int _strlen(char *s)
{
int i = 0;

while (s[i])
{
i++;
}

return (i);
}
