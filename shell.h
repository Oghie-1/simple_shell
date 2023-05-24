#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/* Macro definitions */
#define win(x) write(STDOUT_FILENO, x, _strlen(x))
#define din() write(STDOUT_FILENO, "###\n", 4)

#define ERR_EXIT(a, b, c)\
do {\
write(STDERR_FILENO, a, _strlen(a));\
write(STDERR_FILENO, ": ", 2);\
write(STDERR_FILENO, b, _strlen(b));\
write(STDERR_FILENO, ": exit: Illegal number: ", 24);\
write(STDERR_FILENO, c, _strlen(c));\
write(STDERR_FILENO, "\n", 1);\
} while (0)

#define ERR_EXE(a, b, c)\
do {\
write(STDERR_FILENO, a, _strlen(a));\
write(STDERR_FILENO, ": ", 2);\
write(STDERR_FILENO, b, _strlen(b));\
write(STDERR_FILENO, ": ", 2);\
write(STDERR_FILENO, c, _strlen(c));\
write(STDERR_FILENO, ": not found", 11);\
write(STDERR_FILENO, "\n", 1);\
} while (0)


/* Function prototypes */
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char **tokenizer(char *str, const char *delim);
char *auto_cat(char **path, char *name);
int fork_help(char **av);
int print_env(char **env);
int _atoi(int *status, const char *s);
char *_strdup(const char *str);
char *_intstr(int num);
char *var_finder(const char *var, char **env);
void free_array(char **array);
int stress(char **array, char **argv, char **env, char **p_t, int i, int *e_c);
int shell_run(int go);

#endif /* SHELL_HEADER_H */

