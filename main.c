#include "shell.h"

/**
 * main - A simple shell that executes programs in the system.
 *
 * @argc: Num of args from the command line, passed to shell at launch.
 * @argv: Array of args passed to shell at launch.
 * @env: Array of env variables.
 * Return:  0 upon success, or the number given to "exit".
 */

int main(int argc, char **argv, char **env)
{
char **free_path_token = tokenizer(path_finder("PATH", env), ":=");
/* Tokenizes the "PATH" environmental variable using the delimiter ":=" */

char **path_token = free_path_token + 1;

/* Points to the second element of free_path_token, skipping the variable name */

char *line = NULL;
char **array = NULL;
ssize_t go = 0;
size_t count = 0;
int exit_code = 0;
int i = 0;
(void)argc;

while (42)
{
count = 0;
line = NULL;
array = NULL;
i++;

write(STDIN_FILENO, "\033[1;35m$\033[0m ", 13);
/* Prints the shell prompt "$" in magenta color */

go = getline(&line, &count, stdin);
/* Reads a line of input from the user */

if (shell_run(go))
{
free(line);
break;
}
/* Checks if the shell should exit based on the return value of run_shell */

if (line != NULL && line[0] == '\n')
{
free(line);
line = NULL;
}
/* Handles empty lines by freeing the line and setting it to NULL */

if (line != NULL)
{
array = tokenizer(line, "\n ");
free(line);
}
/* Tokenizes the line using the delimiter "\n " and frees the line */

if (stress(array, argv, env, path_token, i, &exit_code))
break;
/* Executes the command and handles shell functionality */

free_array(array);
/* Frees the array of tokens */
}

free_array(free_path_token);
free_array(array);
/* Frees the arrays used for tokenization */

return exit_code;
/* Returns the exit code */
}

