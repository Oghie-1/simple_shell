#include "shell.h"


/* Helper function to skip leading whitespace */
static char *skip_whitespace(char *str)
{
while (isspace(*str))
{
str++;
}
return str;
}

/* Helper function to check if a character is a quote character */
static int is_quote_char(char c)
{
return c == '"' || c == '\'';
}

/* Helper function to find the next token in the command string */
static char *find_next_token(char *str)
{
char *token_end = str;
int in_quote = 0;

while (*token_end != '\0')
{
if (isspace(*token_end) && !in_quote)
{
break; /* End of token reached */
}
else if (is_quote_char(*token_end))
{
in_quote = !in_quote; /* Toggle in_quote for quote handling */
}
token_end++;
}

return token_end;
}

/* Function to parse command into arguments with proper handling */
void parse_command(char *command, char *args[])
{
int i = 0;
char *token = command;

char *token_end;
size_t token_len;

while (*token != '\0' && i < MAX_NUM_ARGS)
{
token = skip_whitespace(token);

/* Handle quoted strings */
if (is_quote_char(*token))
{
token++; /* Move past the quote character */
token_end = find_next_token(token);

if (*token_end == '\0')
{
    handle_error("Unmatched quote character");
    return;
}

/* Allocate memory for the token (excluding quotes) */
token_len = token_end - token;
args[i] = (char *)malloc(token_len + 1);
if (args[i] == NULL)
{
    handle_error("Memory allocation error");
    return;
}

/* Copy the token (excluding quotes) into args[i] */
strncpy(args[i], token, token_len);
args[i][token_len] = '\0';

/* Move to the next token (after the closing quote character) */
token = token_end + 1;
}
else
{

/* Allocate memory for the token */
token_len = token_end - token;
args[i] = (char *)malloc(token_len + 1);
if (args[i] == NULL)
{
handle_error("Memory allocation error");
return;
}

/* Copy the token into args[i] */
strncpy(args[i], token, token_len);
args[i][token_len] = '\0';

/* Move to the next token */
token = token_end;
}

i++;
}

args[i] = NULL; /* Null-terminate the args array */
}
