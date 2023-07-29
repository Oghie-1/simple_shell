#include "shell.h"

/**
 * print_alias - Prints the alias in the form name='value'
 * @name: The alias name
 * @value: The alias value
 */
void print_alias(char *name, char *value)
{
printf("%s='%s'\n", name, value);
}

/**
 * alias_builtin - Handle the alias builtin command
 * @args: Pointer to the array of arguments for the command
 * @aliases: Pointer to the array of alias structures
 */
void alias_builtin(char *args[], Alias aliases[])
{
int i, j;

if (args[1] == NULL)
{
/* Print all aliases if no arguments are provided */
for (i = 0; i < MAX_ALIASES; i++)
{
if (aliases[i].name != NULL)
print_alias(aliases[i].name, aliases[i].value);
}
}
else
{
/* Handle individual aliases */
for (i = 1; args[i] != NULL; i++)
{
char *name = args[i];
char *value = strchr(name, '=');

if (value != NULL)
{
/* If name contains '=', it's an alias definition */
*value = '\0'; /* Split name and value */
value++;

/* Check if the alias already exists, if yes, update its value */
for (j = 0; j < MAX_ALIASES; j++)
{
if (aliases[j].name != NULL && strcmp(aliases[j].name, name) == 0)
{
free(aliases[j].value);
aliases[j].value = strdup(value);
break;
}
}

/* If the alias doesn't exist, create a new one */
if (j == MAX_ALIASES)
{
for (j = 0; j < MAX_ALIASES; j++)
{
if (aliases[j].name == NULL)
{
aliases[j].name = strdup(name);
aliases[j].value = strdup(value);
break;
}
}
}
}
else
{
/* If name doesn't contain '=', it's an alias query */
for (j = 0; j < MAX_ALIASES; j++)
{
if (aliases[j].name != NULL && strcmp(aliases[j].name, name) == 0)
{
print_alias(aliases[j].name, aliases[j].value);
break;
}
}
}
}
}
}

