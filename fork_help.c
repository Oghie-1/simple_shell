#include "shell.h"

/**
 * fork_help - fork to create child process and execute command
 *
 * @av: command line arguments
 * Return: 1 on failure, 0 on success
 */
int fork_help(char **av)
{
pid_t forked_val;

forked_val = fork();
if (forked_val == -1)
return (1);

if (forked_val == 0)
{

/** Child process **/
if (execve(av[0], av, NULL) == -1)

exit(1); /** Failed to execute command, exit with failure status **/
}

else

{
        
/** Parent process */
wait(NULL); /** Wait for the child process to complete */

return (0); /** Return success status **/
}

return (0);
}

