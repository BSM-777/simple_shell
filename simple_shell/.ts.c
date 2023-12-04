#include "shell.h"

int main(int ac, char **argv)
{
    char *line = NULL;
    /* char **command = NULL; */
    int status;
    (void) ac;
    (void) argv;

    while (1)
    {
        line = read_line();/*t9ra lcommand*/
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))/*ila kan terminal rada tprinti makanch matprintich*/
                write(STDOUT_FILENO,"\n", 1);
            return (status);
        }
        free(line);
/*katfar9 l command*/
        command = tokenize_command(line); 

        status = _execute(command, argv); *//*bayna ach kadir*/  
    }
}
