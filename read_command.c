#include "shell.h"


char *read_command()
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters = getline(&buffer, &bufsize, stdin);

if (characters == -1)
{
return NULL;
}

/* Remove the newline character at the end of the command */
buffer[strcspn(buffer, "\n")] = '\0';

return buffer;
}

