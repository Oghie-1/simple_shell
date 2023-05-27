#include "shell.h"

/**
 * show_hlp - shows help  for built-in commands
 */

void show_help(void)
{
puts("\nShell Version 1.0.0\n\n");
puts("Usage: ./hsh\n\n");
puts("Shell built-in commands:\n\n");
puts("help\t\tDisplay this help information\n\n");
puts("cd [dir]\tChange the current working directory\n\n");
puts("env\t\tDisplay the environment variables\n\n");
puts("setenv\t\tSet an environment variable\n\n");
puts("unsetenv\tUnset an environment variable\n\n");
puts("exit\t\tExit the shell\n\n");
}
