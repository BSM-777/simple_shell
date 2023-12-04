#include "shell.h"
/* execute dyal prompt m3a error's dyal commands*/
void execute_command(char** args)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0)
    {
        /*Child process*/

        /*Execute the command*/
        if (execve(args[0], args, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        int status;
        waitpid(child_pid, &status, 0);
    }
}