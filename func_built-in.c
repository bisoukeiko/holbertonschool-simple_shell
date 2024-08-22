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

	exit(EXIT_SUCCESS);
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


/**
 * func_ctrlC - shell should not quit with ctrl+C
 * @signum: The signal number
 * Return: Nothing
 */

void func_ctrlC(int signum)
{
	(void)signum;
	write(STDIN_FILENO, "\n$ ", 3);
}

