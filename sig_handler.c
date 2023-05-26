#include "shell.h"

/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigint(int signal)
{
(void) signal;
_putchar('\n');
prompt();
}

/**
 * handle_sigquit - Signal handler for SIGQUIT (Ctrl+\)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigquit(int signal)
{
(void) signal;
_puterror("Quit (core dumped)\n");
exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Signal handler for SIGTSTP (Ctrl+Z)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigstp(int signal)
{
(void) signal;
_puts("\n");
prompt();
}
