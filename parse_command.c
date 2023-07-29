#include "shell.h"

/**
 * parse_command - Parse a command into individual arguments
 * @command: Pointer to the input command string
 * @args: Pointer to the array where arguments will be stored
 */
void parse_command(char *command, char *args[])
{
char *token = strtok(command, " "); /* Use strtok() to tokenize the command string */
int i = 0;

while (token != NULL && i < MAX_NUM_ARGS)
{
if (token[0] != '#') /* Check if the token is not a comment (line starts with #)*/
args[i] = token; /* Store each token (argument) in the arguments array */
token = strtok(NULL, " "); /* Move to the next token */
i++;
}

args[i] = NULL; /* Set the last element to NULL to indicate the end of arguments */
}
