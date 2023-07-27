#include "shell.h"

void display_prompt()
{
char *cwd = getcwd(NULL, 0); /* Use dynamic memory allocation */

if (cwd != NULL)
{
printf("%s@%s$ ", getenv("USER"), cwd);
free(cwd); /* Free the dynamically allocated memory for cwd */
}
else
{
perror("Error getting current working directory");
printf("shell$ ");
}
}
