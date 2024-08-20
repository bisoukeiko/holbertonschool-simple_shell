#include "shell.h"

/**
 * process_command - Check the full path of the command and
 *                   run it if it is executable
 * @command: An array of command and its arguments
 * @argv: An array containing arguments for the entire program
 * Return: Nothing
 */

void process_command(char ** command, char **argv)
{
	char *tmp_command = command[0];

	if (command[0][0] != '/')
	{
		command[0] = get_fullpath(command[0]);
	}

	if (!command[0])
	{
		fprintf(stderr,"%s: 1 %s: not found\n", argv[0], tmp_command);
		return;
	}

	if (access(command[0], X_OK) == 0)
	{
		execute(command, argv);
	}
}
