#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <dirent.h>
extern char **environ;
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char **tokeniseParse(char *input);
int check(char *execut);
char *pathSearch(char *av);
int handleBuiltIn(char **args);
void handle_env(void);
#endif
