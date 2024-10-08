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

	signal(SIGINT, func_ctrlC);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("%s", prompt);
		}

		lineptr = get_input(lineptr, &nread);
		command = get_command(lineptr, nread);

		if (command && command[0])
		{
			process_command(command, argv);
		}

		for (index = 0; command[index] != NULL; index++)
		{
			free(command[index]);
		}
		free(command);
	}

	return (0);
}
