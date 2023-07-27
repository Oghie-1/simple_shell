#include "shell.h"

/* Function to handle errors and exit */
void handle_error(const char *message)
{
fprintf(stderr, "Error: %s\n", message);
exit(EXIT_FAILURE);
}

/* Function to free allocated memory in args[] */
void free_memory(char *args[])
{
int i;
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
args[i] = NULL;
}
}

int main(int argc, char **argv)
{
char *command;
size_t n = 0;
char *args[MAX_NUM_ARGS + 1];

/* Set the shell name */
shell = *argv;

(void)argc;

if (!isatty(STDIN_FILENO))
{
if (getline(&command, &n, stdin) == -1)
{
handle_error("getline() failed");
}

command[strcspn(command, "\n")] = '\0';
parse_command(command, args);
execute_command(args);

free(command);
return 0;
}

while (1)
{
display_prompt();
command = read_command();
printf("</> ");
if (getline(&command, &n, stdin) == -1)
{
handle_error("getline() failed");
}

command[strcspn(command, "\n")] = '\0';
parse_command(command, args);

if (strcmp(args[0], "exit") == 0)
{
free_memory(args); /* Free allocated memory in args[] */
free(command);     /* Free dynamically allocated memory for command */
command = NULL; /*Set command to NULL to avoid issues */
break;
}

execute_command(args);
free_memory(args); /* Free allocated memory in args[] */
free(command);     /* Free dynamically allocated memory for command */
}

return 0;
}
