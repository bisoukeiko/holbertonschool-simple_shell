#include "shell.h"

/**
 * execute - execute command path, child process
 * @args: An array of command
 * Return: Nothing
 */

void execute(char **command, char **argv)
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

		if (execve(command[0], command, NULL) == -1)
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
	}
}
