#include "shell.h"

/**
 * execute_command - forks and executes commands
 * @args: pointer to arguments
 */

void execute_command(char *args[])

{
int status;
pid_t pid;

#if 0

char cmd[100], shell[100];

#endif

#if 0
FILE *fp;

snprintf(cmd, sizeof(cmd), "ps -p %d -o comm=", ppid);
fp = popen(cmd, "r");
if (fp == NULL)
perror("Failed to execute command\n");
if (fgets(shell, sizeof(shell), fp) == NULL)
perror("Failed to read output\n");
pclose(fp);

#endif

#if 1

++line_number;

#endif

pid = fork();
if (pid == 0)
{
execvp(args[0], args);
#if 0
     
printf("%s: %d: %s: not found\n", shell, __LINE__, args[0]);

#else

printf("%s: %d: %s: not found\n", shell, line_number, args[0]);

#endif

exit(1);
}
else if (pid > 0)
{
wait(&status);
}
else
{
perror("Error: failed to fork\n");
exit(1);
}
}

