#include "shell.h"

char** tokenize_command(char* command)
{
    char** tokens = malloc(MAX_INPUT_SIZE * sizeof(char*)); /*hadi bach y9dar i9ra commande twila*/

    if (tokens == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char* token = strtok(command, " \t\n");
    int i = 0;

    while (token != NULL)
    {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, " \t\n");
    }

    tokens[i] = NULL;

    return tokens;
}
