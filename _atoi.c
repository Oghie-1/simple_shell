#include "shell.h"

/**
 * _atoi - Convert a character-represented number into an integer.
 *
 * @status: Pointer to a flag representing whether the character is a number or not.
 * @s: Character string.
 * Return: Converted integer.
 */
int _atoi(int *status, const char *s)
{
int i = 0;
int sum = 0;
int mul = 1;

while (s[i])
{
i++;
}

while (i--)
{
if (s[i] > '9' || s[i] < '0')
{
*status = 1;
return 0;  /** Invalid number, return 0 */
}
sum += (s[i] - '0') * mul;
mul *= 10;
}

return sum;
}

