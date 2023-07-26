#include "shell.h"

void display_prompt()
{
char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != NULL) {
printf("%s@%s$ ", getenv("USER"), cwd);
} else {
perror("Error getting current working directory");
printf("shell$ ");
}
}
