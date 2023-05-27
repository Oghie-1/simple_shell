#include "shell.h"

/**
 * execute_command - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */

int execute_command(char **argv)
{
pid_t id;
int status = 0;
char *cmd_path, *envp[2];

if (argv == NULL || *argv == NULL)
return status;
if (check_for_builtin(argv))
return status;

id = fork();
if (id < 0)
{
print_error_message("fork");
return 1;
}
if (id == 0)
{
envp[1] = NULL;
cmd_path = NULL;
if (argv[0][0] != '/')
cmd_path = find_executable_in_path(argv[0]);
if (cmd_path == NULL)
cmd_path = argv[0];
if (execve(cmd_path, argv, envp) == -1)
{
perror(argv[0]);
free_token_array(argv);
free_last_input();
exit(EXIT_FAILURE);
}
}
else
{
do
{
waitpid(id, &status, WUNTRACED);
}
while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return status;
}
