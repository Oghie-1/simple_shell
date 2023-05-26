#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/* Macros */
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":" /* Separator used in the PATH environment variable */
#define PROMPT "$ " /* Shell prompt symbol */
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

/* prompt.c */
/* Function to display the shell prompt */
void display_prompt(void);

/* get_input.c */
/* Function to read user input from the console */
char *read_input(void);

/* Function to free the memory allocated for the last input */
void free_last_input(void);

/* get_line.c */
/* Function to get a line from input */
void *get_line(void);

/* signal_handler.c */
/* Signal handler for SIGTSTP (Ctrl+Z) */
void handle_sigstp(int signal);
/* Signal handler for SIGINT (Ctrl+C) */
void handle_sigint(int signal);
/* Signal handler for SIGQUIT (Ctrl+\) */
void handle_sigquit(int signal);


/* built-in functions */
/* Check if a command is a built-in function */
int check_for_builtin(char **args);
/* Execute a built-in function */
int execute_builtin(char *command, char **args);
/* Display help information */
void show_help(void); 
/* Exit the shell */
void exit_shell(char **args);
/* Change the current directory */
void change_directory(char **args);
/* Set an environment variable */
int set_environment_variable(char **args);
/* Unset an environment variable */
int unset_environment_variable(char **args);
/* Display the environment variables */
int display_environment(void);
/* Clear the screen */
int clear_screen(char **args);

/* parser.c */
/* Tokenize the user input */
char **tokenize_input(char *input);
/* Tokenize a string based on a delimiter */
char **tokenize_string(char *str, const char *delim);

/* execute.c */
/* Execute a command */
int execute_command(char **args);

/* find_in_path.c */
/* Find the executable in the directories specified by PATH */
char *find_executable_in_path(char *command);

/* get_env.c */
/* Get the value of an environment variable */
char *get_environment_variable(const char *name);

/* free.c */
/* Free memory allocated for error handling */
void free_error_arguments(char **argv, char *arg);
/* Free memory allocated for the PATH variable */
void free_path_variable(void);
/* Free memory allocated for token array */
void free_token_array(char **tokens);

/* utility functions */
/* Get the length of a string */
int get_string_length(const char *str);
/* Compare two strings up to a certain length */
int compare_strings_n(const char *s1, const char *s2, size_t n);
/* Compare two strings */
int compare_strings(const char *s1, const char *s2);
/* Find a character in a string */
char *find_character(char *s, char c);
/* Find a substring in a string */
char *find_substring(char *haystack, char *needle);
/* Copy a string */
char *copy_string(char *dest, char *src);
/* Duplicate a string */
char *duplicate_string(const char *str);
/* Concatenate two strings */
char *concatenate_strings(char *dest, const char *src);
/* Get the length of the initial substring containing only certain characters */
unsigned int get_initial_substring_length(char *s, char *accept);
/* Print a character */
int print_character(char c);
/* Fill a block of memory with a character */
char *fill_memory_with_character(char *s, char c, unsigned int n);
/* Convert a string to an integer */
int convert_string_to_integer(const char *str);
/* Copy a block of memory */
char *copy_memory_block(char *dest, char *src, unsigned int n);
/* Allocate zeroed memory */
void *allocate_zeroed_memory(unsigned int nmemb, unsigned int size);
/* Reallocate memory */
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size);

/* error.c */
/* Print a string */
void print_string(char *str);
/* Print an error message */
void print_error_message(char *err);

/* find_in_path.c */
/* Get the value of the PATH environment variable */
char *find_executable_in_path(char *command);


#endif
