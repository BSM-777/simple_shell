#include "shell.h"
/* task dyal prompt */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    n = getline(&line, &len, stdin);
    if (n == -1)
    {
        return NULL; // No need to free line here
    }

    return (line);
}
