#include "shell.h"

/**
 * count_path - Count the number of directories in PATH
 * @path_copy: PATH directories
 * Return: The number of directories in PATH
 */

int count_path(char *path_copy)
{
	int cnt_path = 0;
	char *token;

	token = strtok(path_copy, ":");
	while (token)
	{
		cnt_path++;
		token = strtok(NULL, ":");
	}

	return (cnt_path);
}


/**
 * allocate_path - Reserve memory to store the directory paths
 *                 in the PATH environment variable
 * @cnt_path: The number of directories in PATH
 * Return: A pointer to an array of allocated directory paths
 */

char **allocate_path(int cnt_path)
{
	char **path_dir;

	path_dir = malloc(sizeof(char *) * (cnt_path + 1));
	if (!path_dir)
	{
		perror("Error: Memory allocation");
		return (NULL);
	}

	return (path_dir);
}

/**
 * store_path - Store PATH directories in an array
 * @path_dir: A pointer to an array of allocated directory paths
 * @path_copy: Copy of PATH directories
 * Return: 0 on success, -1 if memory allocation fails
 */

int store_path(char **path_dir, char *path_copy)
{
	int index = 0;
	char *token;

	token = strtok(path_copy, ":");

	while (token)
	{
		path_dir[index] = strdup(token);
		if (!path_dir[index])
		{
			perror("Error: Memory allocation for token");

			while (index > 0)
			{
				free(path_dir[--index]);
			}
			return (-1);
		}

		index++;
		token = strtok(NULL, ":");
	}

	path_dir[index] = NULL;

	return (0);
}


/**
 * tokenize_path - Tokenize directories from the PATH
 * @path_dir: A pointer to an array for store the directory paths
 * Return: A pointer to an array of directory paths, or NULL on error
 */

char **tokenize_path(char **path_dir)
{
	char *path = getenv("PATH");
	char *path_copy;
	int cnt_path;

	if (!path)
	{
		perror("Error: PATH");
		return (NULL);
	}

	path_copy = _strdup(path);
	if (!path_copy)
	{
		perror("Error: Memory allocation for path");
		return (NULL);
	}

	cnt_path = count_path(path_copy);
	free(path_copy);
	path_dir = allocate_path(cnt_path);
	if (!path_dir)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
	{
		perror("Error: Memory allocation for path");
		free(path_dir);
		return (NULL);
	}

	if (store_path(path_dir, path_copy) == -1)
	{
		free(path_dir);
		free(path_copy);
		return (NULL);
	}

	free(path_copy);
	return (path_dir);
}
