#include "shell.h"

/**
 * _strlen - Measures the length of a string.
 *
 * @s: Pointer to the string.
 * Return: Length of the string.
 *
 *
 */

size_t _strlen(const char *s)

{
size_t length = 0;

while (s[length] != '\0')
length++;

return length;
}

