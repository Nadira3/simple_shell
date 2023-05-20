#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFSIZE 50

typedef struct var
{
	const char *str;
	char (*func_ptr)(char *arg);
} var_func;
char *skip_spaces(char *str);
char **parse_input(char *user_input);
char *path(char *command);
char *read_input(void);
char *_strcat(char *str1, char *str2);
char *_strcpyp(char *str1, char *str2);
char *_strcpy(char *str1, char *str2);
int _strcmp(char *str1, char *str2);
char (*env_func)(char *);
char (*cd_func)(char *);
char (*exit_func)(char *);
char (*setenv_func)(char *);
char (*unsetenv_func)(char *);
int wordlen(char *str);
int _strlen(char *str);
int num_words(char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char (*interpret_func(char *arg_command))(char *arg);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
char *_strtok(char *str, char *delim);
#endif
