#include "shell.h"
/*main.c hiya li radi ykon fiha ga3 l executable functions*/
int main() {
    while (1) /*hadi loupe dyal task 1 */
    {
        char *command = read_line();
        if (command == NULL)
        {
            /*Handle EOF or other errors here*/ 
            break; /*Exit the loop or take appropriate action*/ 
        } else if (strcmp(command, "/bin/ls\n") == 0)
        {
            char *ls_args[] = {"/bin/ls", NULL};
            execute_command(ls_args);
        } else {
            char **args = tokenize_command(command);
            if (args[0] != NULL) {
                execute_command(args);
            }
            for (int i = 0; args[i] != NULL; i++)
            {
                free(args[i]);
            }
            free(args);
        }
        free(command); /*Free memory allocated for command*/ 
    }
    return (0);
}
/*int executing()
{
    char *command = "ls";
    char *path = _getpath(command);

    if (path != NULL) {
        printf("Executing %s from %s\n", command, path);
        // Now you can execute the command using execv() or system()
        // For example, using system:
        // char execute_command[MAX_PATH_LENGTH + strlen(command) + 1];
        // sprintf(execute_command, "%s", command);
        // system(execute_command);
        free(path);
    } else {
        printf("Command not found.\n");
    }

    return 0;
}*/ /*hadi dyal task dyal execute ls nichal t9dar tkml 3liha wla dir wahda bohdk */