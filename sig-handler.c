#include "shell.h"
#include <signal.h>

/* Global variable to track if a child process is running */
volatile sig_atomic_t child_running = 0;

/* Signal handler for SIGINT */
void sigint_handler(int sig)
{
if (child_running)
{
/* If a child process is running, forward the SIGINT to the child process */
kill(0, SIGINT);
}
else
{
/* If no child process is running, clean up resources and exit the shell gracefully */
printf("\nTerminating the shell...\n");
/* Add any necessary cleanup tasks specific to your shell here */
/* For example, closing files, deallocating memory, etc. */
exit(EXIT_SUCCESS);
}
}

/* Signal handler for SIGTERM and SIGHUP */
void sigterm_handler(int sig)
{
/* Clean up resources and exit the shell gracefully for SIGTERM and SIGHUP */
printf("\nReceived signal %d. Terminating the shell...\n", sig);
/* Add any necessary cleanup tasks specific to your shell here */
/* For example, closing files, deallocating memory, etc. */
exit(EXIT_SUCCESS);
}

/* Function to set up signal handlers */
void setup_signal_handlers()
{
struct sigaction sa;
sa.sa_flags = 0;
sa.sa_handler = sigint_handler;
sigemptyset(&sa.sa_mask);
sigaction(SIGINT, &sa, NULL);

sa.sa_handler = sigterm_handler;
sigaction(SIGTERM, &sa, NULL);
sigaction(SIGHUP, &sa, NULL);
}

/* Function to handle SIGINT when a child process is running */
void handle_sigint_child_running()
{
child_running = 1;
printf("\nChild process is running. Press Ctrl+C again to terminate the child.\n");
}

/* Function to handle SIGINT when no child process is running */
void handle_sigint_no_child()
{
child_running = 0;
/* Add any necessary actions when no child process is running and SIGINT is received */
/* For example, you may want to print a message or perform other tasks specific to the shell */
printf("\nShell: Received SIGINT. Press Ctrl+C again to terminate the shell.\n");
}
