#include "shell.h"

/**
 * display_prompt - Print shell prompt to stdin stream.
 *
 * Return: void.
 */

void display_prompt(void)
{
_puts(PROMPT);
fflush(stdout);
}

