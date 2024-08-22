#ifndef _SHELL_H_
#define _SHELL_H_


#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <signal.h>

/*----- Prototype -----*/
char *get_input(char *lineptr, ssize_t *nread);
char **get_command(char *lineptr, ssize_t nread);
void execute(char *full_path, char **command, char **argv, int fg);
int count_tokens(char *lineptr_copy, const char *delim);
char **tokenize_command(char *lineptr, char *lineptr_copy,
			int cnt_token, const char *delim);
char *get_fullpath(char *command);
char **tokenize_path(char **path_dir);
int store_path(char **path_dir, char *path_copy);
char **allocate_path(int cnt_path);
int count_path(char *path_copy);
void free_path_dir(char **path_dir);
void process_command(char **command, char **argv);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
void func_env(void);
void func_exit(char **command);
char *_getenv(char *name);
void func_notfound(char *full_path, char **command);
void func_ctrlC(int signum);
void func_exit(char **command);

/*---------------------*/

extern char **environ;

#endif
