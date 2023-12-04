#include "shell.h"
/*had lcode dyal execution dyal task PATH*/
char *_getenv(char *var)
{
    char *tmp, *key, *value, *env;
    int i;

    for (i = 0; environ[i]; i++)
    {
        tmp = strdup(environ[i]);
        key = strtok(tmp, "=");
        if (strcmp(key, var) == 0)
        {
            value = strtok(NULL, "\n");
            env = strdup(value);
            return (env);

        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
/*fhad lcode radi yt9asm l PATH */