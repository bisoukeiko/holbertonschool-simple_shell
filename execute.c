#include "shell.h"

/**
 * execute - execute command path, child process
 * @args: An array of command
 * Return: Nothing
 */

void execute(char **args)
{
	pid_t pid = fork();
	int status;
	int index;

	if (pid < 0)
	{
		perror("error:fork");
	}
	else if (pid == 0)
	{

		if (execve(args[0], args, NULL) == -1)
		{
			for (index = 0; args[index] != NULL; index++)
			{
				free(args[index]);
			}
			free(args);

			perror("error: excve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
