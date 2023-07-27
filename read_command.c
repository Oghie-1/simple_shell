#include "shell.h"

char *read_command()
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t characters = getline(&buffer, &bufsize, stdin);

if (characters == -1)
{
if (feof(stdin))
{
/* Handle EOF (Ctrl+D) */
printf("\nReceived EOF (Ctrl+D). Exiting the shell.\n");
}
else
{
/* Handle other errors during input reading */
perror("Error: getline() failed\n");
}

/* Return NULL to indicate no command was read */
return NULL;
}

/* Remove the trailing newline character at the end of the command */
buffer[strcspn(buffer, "\n")] = '\0';

/* Check for an empty command (only whitespace characters) */
char *temp = buffer;
while (*temp != '\0')
{
if (!isspace(*temp))
{
/* Non-empty command, return the buffer */
return buffer;
}
temp++;
}

/* Free memory if the command is empty (only whitespace characters) */
free(buffer);

/* Return NULL to indicate no command was read */
return NULL;
}
