#include "shell.h"

/**
 * tokenizer - parse a str to tokens using delimiters
 *
 * @str: string to be parsed
 * @delim: delimiter
 * Return: array of pointers to tokens
 *
 *
 */

char **tokenizer(char *str, const char *delim)
{
int i = 0;
char *str_1 = NULL, *str_2 = NULL, *ptr = NULL, **ar = NULL;

if (!(str) || !(delim))
return (NULL);
/* Checks if str or delim is NULL and returns NULL if either is true */

str_1 = _strdup(str);
str_2 = _strdup(str);
/* Creates two duplicate copies of str */

if (!(str_1) || !(str_2))
return (NULL);
/* Checks if memory allocation fails and returns NULL if true */

ptr = strtok(str_1, delim);
/* Tokenizes the first copy of str using strtok */

if (ptr == NULL)
return (NULL);
/* Checks if no token is found and returns NULL if true */

for (i = 0; ptr != NULL; i++)
{
ptr = strtok(NULL, delim);
}
/* Counts the number of tokens by repeatedly calling strtok */

ar = malloc(sizeof(char *) * (i + 1));
if (ar == NULL)
return (NULL);
/* Allocates memory for an array of pointers to tokens */

ptr = strtok(str_2, delim);
/* Tokenizes the second copy of str using strtok */

if (ptr == NULL)
return (NULL);
/* Checks if no token is found and returns NULL if true */

for (i = 0; ptr != NULL; i++)
{
ar[i] = _strdup(ptr);
ptr = strtok(NULL, delim);
}
/* Duplicates each token and stores it in the array */

ar[i] = NULL;
free(str_1);
free(str_2);
/* Frees the duplicate copies of str */

return (ar);
/* Returns the array of tokens */
}

