#include "shell.h"

/**
 * main - Display a prompt and wait for the user to type a command.
 *        A command line always ends with a new line.
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	ssize_t nread;
	char **command;
	int index;

	if (argc < 1)
	{
		fprintf(stderr, "Error: %s\n", argv[0]);
		return (1);
	}


	while (1)
	{
		printf("%s", prompt);

		lineptr = get_input(lineptr, &nread);

		command = get_command(lineptr, nread);

		if (command[0][0] != '/')
		{
			command[0] = get_fullpath(command[0]);
		}

		execute(command, argv);

		for (index = 0; command[index] != NULL; index++)
		{
			free(command[index]);
		}

		free(command);

	}

	return (0);
}
