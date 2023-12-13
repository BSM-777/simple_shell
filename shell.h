#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define MAX_PATH_LENGTH 512

extern char **environ;



char **tokenize_command(char *command);
void print_prompt(void);
int main(void);
int execute_command(char **args);
char *read_line(void);
char *_getenv(char *var);
int executing(void);
char *_getpath(char *cmd);

char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);


#endif
