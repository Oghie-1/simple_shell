#include "shell.h"

/**
 * find_executable_in_path - Looks for a command in each directory specified in the PATH
 *                environment variable
 * @command: Pointer to the `command` string to look for.
 *
 * Return: Pointer to a string containing the full path (success) if it is found,
 *         or NULL if it is not found (failure).
 */
char *find_executable_in_path(char *command)
{
struct stat st;
int stat_ret, i;
char buf[PATH_MAX_LENGTH], *path, *ret, **dir;

path = get_path();
if (!path)
return NULL;
dir = tokenize(path, PATH_SEPARATOR);
if (!dir)
return NULL;
for (i = 0; dir[i]; i++)
{
_memset(buf, 0, PATH_MAX_LENGTH);
_strcpy(buf, dir[i]);
_strcat(buf, "/");
_strcat(buf, command);
stat_ret = stat(buf, &st);
if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
{
free_tokens(dir);
ret = malloc(sizeof(char) * (strlen(buf) + 1));
if (!ret)
return NULL;
_strcpy(ret, buf);
return ret;
}
}
free_tokens(dir);
return NULL;
}
