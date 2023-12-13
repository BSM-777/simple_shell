#include "shell.h"

/**
 * _getpath - geting the PATH
 * @cmd: the command of user input
 *
 * Return: Always return a 0
*/
char *_getpath(char *cmd)
{
char *path_env, *full_cmd, *dir;
struct stat st;
int i;
(void) i;

path_env = _getenv("PATH");

dir = strtok(path_env, ":");
while (dir)
{
full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
if (full_cmd)
{
_strcpy(full_cmd, dir);
_strcat(full_cmd, "/");
_strcat(full_cmd, cmd);
if (stat(full_cmd, &st) == 0)
{
free(path_env);
return (full_cmd);
}
free(full_cmd), full_cmd = NULL;
}
}
return (0);
}
