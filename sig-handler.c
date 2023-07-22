#include "shell.h"


void handle_sigint(int sig)
{
(void)sig;
printf("\n");
display_prompt();
fflush(stdout);
}

