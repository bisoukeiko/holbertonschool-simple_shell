#include "shell.h"

/**
 * func_exit - exit the shell
 * @command:  An array of command and its arguments
 * Return: Nothing
 */

void func_exit(char **command)
{
	int index;

	for (index = 0; command[index] != NULL; index++)
	{
		free(command[index]);
	}
	free(command);

	exit(0);
}


/**
 * func_env -  prints the current environment
 * Return: Nothing
 */

void func_env(void)
{
	int index;

	for (index = 0; environ[index] != NULL; index++)
	{
		printf("%s\n", environ[index]);
	}
}
