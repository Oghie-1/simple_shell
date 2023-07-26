#include "shell.h"

/**
 * main - main shell program
 * @argc: number of arguments
 * @argv: arrays of CLI arguments
 * Return: 0.
 */

/* Function to handle errors and exit */
void handle_error(const char *message)
{
fprintf(stderr, "Error: %s\n", message);
exit(EXIT_FAILURE);
}

/* Function to free allocated memory in args[] */
void free_memory(char *args[])
{
for (int i = 0; args[i] != NULL; i++)
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

#if 1
shell = *argv;
#endif

(void)argc;

if (!isatty(STDIN_FILENO))
{
if (getline(&command, &n, stdin) == -1)
{
perror("Error: getline() failed\n");
return (1);
}

command[strcspn(command, "\n")] = '\0';
parse_command(command, args);
execute_command(args);

free(command);
return (0);
}

while (1)
{
display_prompt();
command = read_command();
printf("</> ");
if (getline(&command, &n, stdin) == -1)
{
perror("Error: getline() failed\n");
break;
}

command[strcspn(command, "\n")] = '\0';
parse_command(command, args);

if (strcmp(args[0], "exit") == 0)
{
break;
}

execute_command(args);
}

/* Function to handle errors and exit */
void handle_error(const char *message)
{
fprintf(stderr, "Error: %s\n", message);
exit(EXIT_FAILURE);
}

/* Function to free allocated memory in args[] */
void free_memory(char *args[])
{
for (int i = 0; args[i] != NULL; i++)
{
free(args[i]);
args[i] = NULL;
}
}

free(command);
return (0);
}

