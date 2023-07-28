#include "shell.h"

/* Function to display the shell prompt */
void displayShellPrompt(void)
{
char *currentWorkingDir = getcwd(NULL, 0); /* Use dynamic memory allocation to store the current working directory */

if (currentWorkingDir != NULL)
{
printf("%s@%s$ ", getenv("USER"), currentWorkingDir); /* Display the shell prompt with username and current working directory */
free(currentWorkingDir); /* Free the dynamically allocated memory for the current working directory */
}
else
{
perror("Error getting current working directory");
printf("afro@shell$ "); /* Display a fallback prompt if there was an error getting the current working directory */
}
}

