#include "shell.h"

/**
 *get_line - Function to get a line from input.
 *
 *Return: The string entered by the user.
 *
 *
 */

char *get_line(void)
{
/* Static buffer to store input characters */
static char buffer[BUFFER_SIZE];
/* Current position and size of the buffern*/
static int buf_pos = 0, buf_size = 0;
/* Dynamically allocated string to store the input */
char *input_str = NULL;
/* Current character being read */
char current_char;
/* Length of the input string */
int input_len = 0;
while (1)
{
if (buf_pos >= buf_size)
{
/* Read input from standard input */
buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
buf_pos = 0;
if (buf_size == 0)
/* Return the input string if end of input is reached */
return input_str;
else if (buf_size < 0)
{
perror("read");
/*Return NULL in case of an error */
return NULL;
}
}
/* Get the current character from the buffer */
current_char = buffer[buf_pos];

buf_pos++;

if (current_char == '\n')
{
/* Allocate memory for the input string */
input_str = realloc(input_str, input_len + 1);
/* Add null terminator to the input string */
input_str[input_len] = '\0';
/* Return the input string */
return input_str;
}
else
{
/* Allocate memory for the input string */
input_str = realloc(input_str, input_len + 1);
/* Add the current character to the input string */
input_str[input_len] = current_char;
input_len++;
}
}
}
