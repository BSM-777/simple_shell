#include "shell.h"

char *_getpath(char *cmd)
{
    char *path_env, *full_cmd, *dir;
    struct stat st;
    int i;
    /*declaration of variables */

   /* for (i = 0; cmd[i]; i++)
    {
        
    }*/

    path_env = _getenv("PATH"); /*getenv katakhod PATH*/

    dir = strtok(path_env, ":"); /*strtok rada t9asm lPATH, dik ":" hiya fin radi yw9af l search o radi idir lprogram execute ldak lPATH bach ichofo wach khdam*/
    while(dir)
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
/* had loupe ma39altch ach kadir hhh mohima osfy*/
    }
}