#include "shell.h"
/**
 *execute_command - this function for execution of simple shell
 *@args: the arg variable take the value of string
 *
 * Return: the child and the parent pid
 */
int execute_command(char **args)
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
if (execve(args[0], args, environ) == -1) /* Child process */
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(child_pid, &status, 0); /* Parent process */
if (WIFEXITED(status))
{
return (WEXITSTATUS(status));
}
else
{
return (1); /*or another non-zero value to indicate an error*/
}
}
return (0); /*This line should never be reached*/
}
