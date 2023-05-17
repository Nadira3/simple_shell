#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <wait.h>
#define BUFSIZE 1024
char *skipSpaces(char *str);
char **parse_input(char *user_input);
char *read_input(void);
char *_strcat(char *str1, char *str2);
char *_strcpyp(char *str1, char *str2);
char *_strcpy(char *str1, char *str2);
int wordlen(char *str);
int _strlen(char *str);
int numWords(char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
