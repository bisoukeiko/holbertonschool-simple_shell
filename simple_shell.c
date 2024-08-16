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
	char **args;
	int index;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);

		lineptr = get_input(lineptr, &nread);

		args = get_command(lineptr, nread);

		execute(args);

		for (index = 0; args[index] != NULL; index++)
		{
			free(args[index]);
		}

		free(args);

	}

	return (0);
}
