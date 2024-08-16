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
int count_tokens(char *lineptr_copy, const char *delim);
char **copy_tokens(char *lineptr, char *lineptr_copy,
			int cnt_token, const char *delim);






#endif
