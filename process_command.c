#include "shell.h"

/**
 * func_notfound - free memorys and exit programme
 * @full_path: full path of the command
 * @command: An array of command and its arguments
 * Return: Noting
 */

void func_notfound(char *full_path, char **command)
{
	int index;

	if (full_path)
	{
		free(full_path);
	}

	for (index = 0; command[index] != NULL; index++)
	{
		free(command[index]);
	}
	free(command);

	exit(127);
}

/**
 * process_command - Check the full path of the command and
 *                   run it if it is executable
 * @command: An array of command and its arguments
 * @argv: An array containing arguments for the entire program
 * Return: Nothing
 */

void process_command(char **command, char **argv)
{
	char *full_path = NULL;
	int fg = 0;

	if (_strcmp(command[0], "exit") == 0)
		func_exit(command);

	if (_strcmp(command[0], "env") == 0)
	{
		func_env();
		return;
	}

	if (command[0][0] != '/' && command[0][0] != '.')
	{
		full_path = get_fullpath(command[0]);
		if (!full_path)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command[0]);
			func_notfound(full_path, command);
		}

		if (access(full_path, X_OK) == 0)
		{
			fg = 1;
			execute(full_path, command, argv, fg);
		}
	}
	else
	{
		if (access(command[0], X_OK) == 0)
		{
			execute(command[0], command, argv, fg);
		}
		else
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command[0]);
			func_notfound(NULL, command);
		}
	}
}
