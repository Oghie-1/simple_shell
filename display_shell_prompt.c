#include "shell.h"

/* Function to display the shell prompt */
void displayShellPrompt(void)
{
char *username = getenv("USER"); /* Get the value of the "USER" environment variable */
char *currentWorkingDir = getcwd(NULL, 0); /* Use dynamic memory allocation to store the current working directory */



if (username != NULL)
{
printf("%s", username); /* Display the username */
}

else
{

/*  Handle the case when the "USER" environment variable is not set */
perror("Error: USER environment variable is not set");
printf("Unknown"); /* Display a fallback username*/
}

if (currentWorkingDir != NULL)
{
printf("@%s$ ", currentWorkingDir); /*Display the prompt with current working directory */

free(currentWorkingDir); /* Free the dynamically allocated memory for the current working directory */
}
else
{

/* Handle the case when either username or cwd is NULL  */
if (username == NULL)
{
perror("Error getting username");
}

if (currentWorkingDir == NULL)
{
perror("Error getting current working directory");
}
printf("afro@shell$ "); /* Display a fallback prompt if there was an error getting the current working directory */
}
}

