#include "shell.h"

/**
 * _intstr - Convert integer to string.
 *
 * @num: Integer to be converted.
 * Return: Pointer to a dynamically allocated string containing the number.
 */

char *_intstr(int num)
{
char *str;
int len = 0;
int num_copy = num;

/** Determine the length of the string **/
if (num == 0)
len = 1;
else
{
while (num_copy != 0)
{
len++;
num_copy /= 10;
}
}

/** Allocate memory for the string **/
str = malloc(sizeof(char) * (len + 1));
if (str == NULL)
return NULL;

/** Convert the number to string **/
if (num == 0)
{
str[0] = '0';
str[1] = '\0';
}
else
{
int j, k;
for (j = 0, k = len - 1; j < k; j++, k--)
{
char temp = str[j];
str[j] = str[k];
str[k] = temp;
}

str[len] = '\0';
}

return str;
}

