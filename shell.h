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

/* Function prototypes */
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char **tokenizer(char *str, const char *delim);
char *smart_cat(char **path, char *name);
int forking_helper(char **av);
int print_env(char **env);
int custom_atoi(int *status, const char *s);
char *_strdup(const char *str);
char *_itoa(int num);
char *var_finder(const char *var, char **env);
void free_array(char **array);
int life(char **array, char **argv, char **env, char **p_t, int i, int *e_c);
int run_shell(int go);

#endif /* SHELL_HEADER_H */

