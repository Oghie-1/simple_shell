#include "shell.h"

/**
 * get_string_length - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */

int get_string_length(const char *str)
{
int i = 0;

if (!s)
return (0);

while (*s++)
i++;
return (i);
}

/**
 * compare_strings - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if @s1 and @s2 are equal,
 *         a negative value if @s1 is less than @s2,
 *         or a positive value if @s1 is greater than @s2.
 */

int compare_strings(const char *s1, const char *s2)
{
while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
{
s1++;
s2++;
}

return ((int) (*s1) - (*s2));
}

/**
 * compare_strings_n - Compare two strings up to a specified length.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters, negative value
 *         if s1 is less than s2, or positive value if s1 is greater than s2.
 */

int compare_strings_n(const char *s1, const char *s2, size_t n)
{
unsigned char c1, c2;

while (n-- > 0)
{
c1 = (unsigned char) *s1++;
c2 = (unsigned char) *s2++;

if (c1 != c2)
return (c1 - c2);
if (c1 == '\0')
break;
}

return (0);
}

/**
 * find_substring - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *find_substring(char *haystack, char *needle)
{
int i;

for (i = 0; haystack[i] != '\0'; i++)
{
if (haystack[i] == needle[0])
{
int j;
for (j = 0; needle[j] != '\0'; j++)
{
if (haystack[i + j] != needle[j])
{
break;
}
}

if (needle[j] == '\0')
{
return (&haystack[i]);
}
}
}
return (NULL);
}

/**
 **find_character - a function that locates a character in a string
 *
 * @s: pointer to our string array input
 * @c: character to locate from input array
 *
 * Return: first occurence of charatcer or null if not found
*/

char *find_character(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}

/**
 * if c is '\0', you should return
 * the pointer to the '\0' of the
 * string s
*/
if (*s == c)
return (s);
/*return null if not found*/
return (NULL);

}


/**
 * _atoi - Converts a string to an integer.
 * @str: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(const char *str)
{
int i, sign;
unsigned int num;

i = 0;
sign = 1;
num = 0;

while (str[i] != '\0')
{
if (str[i] == '-')
sign *= -1;
else if (str[i] >= '0' && str[i] <= '9')
num = (num * 10) + (str[i] - '0');
else
break;
i++;
}
return (num * sign);
}

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * _memcpy - function that copies memory area
 *
 * @dest: buffer where we will copy to
 * @src: what we are to copy
 * @n: n bytes of @src
 *
 * Return: Always 0 (Success)
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)	
dest[i] = src[i];
return (dest);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}

/**
 * _calloc - a function that allocates
 *           memory for an array using malloc
 *
 *           It is basically the equivalent to
 *           malloc followed by memset
 *
 * @nmemb: size of array
 * @size: size of each element
 *
 * Return: pointer with new allocated memory
 *         or NULL if it fails
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
char *p;

if (nmemb == 0 || size == 0)
return (NULL);

p = malloc(nmemb * size);
if (p == NULL)
return (NULL);

_memset(p, 0, nmemb * size);

return (p);
}

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 *_putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _strspn - a function that gets the
 *           length of a prefix substring
 *
 * @s: pointer to string input
 * @accept: substring prefix to look for
 *
 * Return: the number of bytes in the initial segment
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int i, j;

for (i = 0; s[i]; i++)
{
for (j = 0; accept[j]; j++)
{
if (s[i] == accept[j])
break;
}
if (!accept[j])
return (i);
}

return (i);
}
