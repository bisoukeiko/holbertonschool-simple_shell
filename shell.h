#ifndef _SHELL_H_
#define _SHELL_H_


#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*----- Prototype -----*/
char *get_input(char *lineptr, ssize_t *nread);
char **get_command(char *lineptr, ssize_t nread);
void execute(char **args);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);









#endif
