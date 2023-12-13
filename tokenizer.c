#include "shell.h"

/**
 * tokenize_command - tokenize the input
 * @command: the input of user
 *
 * Return: return the token
*/
char **tokenize_command(char *command)
{
char **tokens = malloc(MAX_INPUT_SIZE * sizeof(char *));
char *token;
int i = 0;  /* Declare i outside the loop */
int j;     /* Declare j outside the loop */

if (tokens == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(command, " \t\n");

while (token != NULL)
{
tokens[i] = strdup(token);

if (tokens[i] == NULL)
{
perror("strdup");
free(tokens);
for (j = 0; j < i; j++)
{
free(tokens[j]);
}
exit(EXIT_FAILURE);
}
i++;
token = strtok(NULL, " \t\n");
}
tokens[i] = NULL;
return (tokens);
}
