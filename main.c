#include "shell.h"

/**
 * main - the main function to read the input with readline()
 *
 * Return: the execution of the input or an error
 */
int main(void)
{
while (1)
{
char *command = read_line();
int i;

if (command == NULL)
{
free(command);
break; /* Exit the loop or take appropriate action */
}
else if (strcmp(command, "/bin/ls\n") == 0)
{
char *ls_args[] = {"/bin/ls", NULL};
execute_command(ls_args);
}
else if (strcmp(command, "exit\n") == 0)
{
free(command);
break;
}
else
{
char **args = tokenize_command(command);

if (args[0] != NULL)
{
execute_command(args);/* Pass only args to execute_command */
}
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
}
free(command);
}
return (0);
}
