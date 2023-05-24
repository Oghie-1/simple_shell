#include "shell.h"

/**
 * auto_cat - append the command to its directory path
 *
 * @path: array of pointers to tokenized path directories
 * @name: the command
 * Return: buffer containing concatenated string of the command and its path
 *
 *
 */

char *auto_cat(char **path, char *name)
{
char *buff = NULL;
int i = 0, ii = 0, v = 0;

if (!(path) || !(name))
return (NULL);

if (name[0] == '/')
return (NULL);

while (path[v] != NULL)
{
/* Allocate memory for the concatenated string */
buff = malloc(sizeof(char) * (_strlen(path[v]) + _strlen(name) + 2));
if (!(buff))
return (NULL);

i = 0;
ii = 0;

/* Copy the path directory to the buffer */
while (path[v][ii])
{
buff[i] = path[v][ii];
i++;
ii++;
}

buff[i] = '/'; /* Append a '/' character */
i++;
ii = 0;

/* Copy the command name to the buffer */
while (name[ii])
{
buff[i] = name[ii];
i++;
ii++;
}

buff[i] = '\0'; /* Add null terminator to the buffer */

/* Check if the concatenated string represents an existing file */
if (access(buff, F_OK) == 0)
{
return (buff); /* Return the buffer if a match is found **/
}
else
free(buff); /* Free the buffer if no match is found */

v++; /** Move to the next directory in the path */
}

return (NULL); /** Return NULL if no matching file is found */
}

