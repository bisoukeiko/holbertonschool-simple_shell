#include "shell.h"

/**
 * free_path_dir - Free an array of path directories
 * @path_dir: A double pointer to an array of path directories
 * Return : Nothing
 */

void free_path_dir(char **path_dir)
{
	int index;

	for (index = 0; path_dir[index] != NULL; index++)
	{
		free(path_dir[index]);
	}

	free(path_dir);
}


/**
 * get_fullpath - Searche for the full path of a command
 * @command: The command name to search for
 * Return: A pointer to the full path of the command if found
 *         the NULL if not found or an error occurs
 */

char *get_fullpath(char *command)
{
	char **path_dir = NULL;
	char *full_path;
	int index;

	path_dir = tokenize_path(path_dir);
	if (path_dir)
	{
		for (index = 0; path_dir[index] != NULL; index++)
		{
			full_path = malloc(_strlen(path_dir[index]) + _strlen(command) + 2);
			if (!full_path)
			{
				perror("Error: Memory allocation for full path");
				free_path_dir(path_dir);
				return (NULL);
			}

			_strcpy(full_path, path_dir[index]);
			_strcat(full_path, "/");
			_strcat(full_path, command);

			if (access(full_path, X_OK) == 0)
			{
				free_path_dir(path_dir);
				return (full_path);
			}

			free(full_path);
		}
	}

	free_path_dir(path_dir);
	return (NULL);
}

