#include "shell.h"

/**
 * get_command - Tokenize a command line and store each token in the array
 * @lineptr: A pointer to the input line read
 * @nread: A pointer to The number of characters read
 * Return: An array
 */

char **get_command(char *lineptr, ssize_t nread)
{
	char *lineptr_copy = NULL;
	char *delim = " \n";
	char **args;
	char *token;
	int cnt_token = 0, index;

	lineptr_copy = malloc(sizeof(char) * (nread + 1));
	if (!lineptr_copy)
	{
		free(lineptr);
		perror("error malloc lineptr_copy");
		exit(EXIT_FAILURE);
	}

	_strcpy(lineptr_copy, lineptr);
	token = strtok(lineptr, delim);

	while (token)
	{
		cnt_token++;
		token = strtok(NULL, delim);
	}
	cnt_token++;

	args = malloc(sizeof(char *) * cnt_token);
	if (!args)
	{
		free(lineptr_copy);
		free(lineptr);
		perror("error: malloc args");
		exit(EXIT_FAILURE);
	}

	token = strtok(lineptr_copy, delim);
	for (index = 0; token != NULL; index++)
	{
		args[index] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!args[index])
		{
			while (--index >= 0)
			{
				free(args[index]);
			}
			free(args);
			free(lineptr_copy);
			free(lineptr);
			perror("error: malloc args[index]");
			exit(EXIT_FAILURE);
		}

		_strcpy(args[index], token);
		token = strtok(NULL, delim);
	}
	args[index] = NULL;

	free(lineptr_copy);
	return (args);
}


/**
 * get_input - Read one line from standard input and return a pointer to it
 * @lineptr: A pointer
 * @nread: A pointer to The number of characters read
 * Return: A pointer to the input line read
 */

char *get_input(char *lineptr, ssize_t *nread)
{
	size_t buffer = 0;

	if (lineptr)
	{
		free(lineptr);
		lineptr = NULL;
	}

	*nread = getline(&lineptr, &buffer, stdin);

	if (*nread == -1)
	{
		free(lineptr);

		if (errno == 0)

		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("error: get_input");
			exit(EXIT_FAILURE);
		}
	}

	return (lineptr);
}


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
