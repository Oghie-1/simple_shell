#include "shell.h"

/**
 * print_string - Prints a string to the standard output stream
 * @str: The string to print
 *
 * Return: void
 */

void print_string(char *str)
{
size_t len = strlen(str);
ssize_t num_written = write(STDOUT_FILENO, str, len);

if (num_written == -1)
{
perror("write");
}
}

/**
 * print_error_message - Prints an error message to the standard error stream
 * @err: The error message to print
 *
 * Return: void
 */

void print_error_message(char *err)
{
size_t len = strlen(err);
ssize_t num_written = write(STDERR_FILENO, err, len);

if (num_written == -1)
{
perror("write");
}
}
