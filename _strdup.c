#include "shell.h"


/**
 * _strdup - Duplicates a string.
 *
 * @str: String to be duplicated.
 * Return: Pointer to the newly allocated duplicated string.
 */

char *_strdup(const char *str)
{
char *dup;
size_t length;
size_t i;

if (str == NULL)
return NULL;

length = _strlen(str);

dup = malloc(sizeof(char) * (length + 1));
if (dup == NULL)
return NULL;

for (i = 0; i < length; i++)
{
dup[i] = str[i];
}

dup[length] = '\0';

return dup;
}

