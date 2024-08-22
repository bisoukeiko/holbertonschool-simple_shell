#include "shell.h"

/**
 * execute - Spawn a child process to execute the specified command
 *           and executes the command
 * @full_path: A pointer to full path command
 * @command: An array of command and its arguments
 * @argv: An array containing arguments for the entire program
 * @fg: flag 1 for fullpath
 * Return: Nothing
 */

void execute(char *full_path, char **command, char **argv, int fg)
{
	pid_t pid = fork();
	int status;
	int index;

	if (pid < 0)
	{
		perror("Error: fork");
	}
	else if (pid == 0)
	{

		if (execve(full_path, command, environ) == -1)
		{
			for (index = 0; command[index] != NULL; index++)
			{
				free(command[index]);
			}
			free(command);

			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (fg == 1)
		{
			free(full_path);
		}
	}

}
