#include "shell.h"

/**
 * count_tokens - Count the number of tokens
 * @lineptr_copy: A pointer to the copied input line
 * @delim: Delimiters
 * Return: The total number of tokens in the input line
 */

int count_tokens(char *lineptr_copy, const char *delim)
{
	int cnt_token = 0;
	char *token;

	token = strtok(lineptr_copy, delim);

	while (token)
	{
		cnt_token++;
		token = strtok(NULL, delim);
	}
	cnt_token++;

	return (cnt_token);
}


/**
 * tokenize_command - Tokenize a command line and store each token in the array
 * @lineptr: A pointer to the orignal input line
 * @lineptr_copy: A pointer to the copied input line
 * @cnt_token: The total number of tokens in the input line
 * @delim: Delimiters
 * Return: A pointer to an array of strings, where each string is a token
 */

char **tokenize_command(char *lineptr, char *lineptr_copy,
			int cnt_token, const char *delim)
{
	char **args = NULL;
	char *token;
	int index;

	args = malloc(sizeof(char *) * (cnt_token + 1));
	if (!args)
	{
		free(lineptr);
		free(lineptr_copy);
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
			free(lineptr);
			free(lineptr_copy);
			perror("error: mallo to the input line readc args[index]");
			exit(EXIT_FAILURE);
		}

		_strcpy(args[index], token);
		token = strtok(NULL, delim);
	}

	args[index] = NULL;

	return (args);

}


/**
 * get_command - Tokenize a command line and store each token in the array
 * @lineptr: A pointer to the orignal input line
 * @nread: A pointer to The number of characters read
 * Return: A pointer to an array of strings, where each string is a token
 */

char **get_command(char *lineptr, ssize_t nread)
{
	char *lineptr_copy = NULL;
	char *delim = " \n";
	char **args;
	int cnt_token;

	lineptr_copy = malloc(sizeof(char) * (nread + 1));
	if (!lineptr_copy)
	{
		free(lineptr);
		perror("error malloc lineptr_copy");
		exit(EXIT_FAILURE);
	}

	_strcpy(lineptr_copy, lineptr);

	cnt_token = count_tokens(lineptr_copy, delim);

	_strcpy(lineptr_copy, lineptr);

	args = tokenize_command(lineptr, lineptr_copy, cnt_token, delim);

	free(lineptr);
	free(lineptr_copy);
	return (args);
}


/**
 * get_input - Read one line from standard input and return a pointer to it
 * @lineptr: A pointer to the input line read
 * @nread: A pointer to the number of characters read
 * Return: A pointer to the input line read
 */

char *get_input(char *lineptr, ssize_t *nread)
{
	size_t buffer = 0;

	*nread = getline(&lineptr, &buffer, stdin);

	if (*nread == -1)
	{
		free(lineptr);
		exit(0);
	}

	return (lineptr);
}
