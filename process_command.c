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

	if (command[0][0] != '/' && command[0][0] != '.')
	{
		full_path = get_fullpath(command[0]);
	}
	else
	{
		full_path = command[0];
	}

	if (!full_path)
	{
		fprintf(stderr, "%s: 1 %s: not found\n", argv[0], command[0]);
		free(full_path);
		return;
	}

	if (access(full_path, X_OK) == 0)
	{
		execute(full_path, command, argv);
	}
}
