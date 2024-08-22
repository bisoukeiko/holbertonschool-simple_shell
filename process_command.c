#include "shell.h"

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
	int fg;

	if (_strcmp(command[0], "exit") == 0)
	{
		func_exit(command);
	}

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
			return;
		}

		if (access(full_path, X_OK) == 0)
		{
			fg = 0;
			execute(full_path, command, argv, fg);
		}
	}
	else
	{
		if (access(command[0], X_OK) == 0)
		{
			fg = 1;
			execute(command[0], command, argv, fg);
		}
	}
}
