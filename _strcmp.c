#include "shell.h"

/**
 * _strcmp - Compares two strings.
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 *
 *
 */

int _strcmp(const char *s1, const char *s2)
{
int i = 0;

while (s1[i] != '\0' && s1[i] == s2[i])
{
i++;
}

return (s1[i] - s2[i]);
}

