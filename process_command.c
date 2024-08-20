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
	if (command[0][0] != '/')
	{
		command[0] = get_fullpath(command[0]);
	}

	if (access(command[0], X_OK) == 0)
	{
		execute(command, argv);
	}
}
