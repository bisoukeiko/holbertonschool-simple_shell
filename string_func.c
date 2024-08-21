#include "shell.h"

/**
 * _strlen - Return the length of a string
 * @str: string
 * Return: the length of a string
 */

int _strlen(char *str)
{
	int length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}


/**
 * _strcpy - Copie the string pointed to by src
 * @dest: the buffer pointed
 * @src: the string pointed
 * Return: pointer
 */

char *_strcpy(char *dest, char *src)
{

	int index;

	for (index = 0; src[index] != '\0'; index++)
	{
		dest[index] = src[index];
	}

	dest[index] = '\0';

	return (dest);

}



/**
 * *_strcat - concatenates two strings
 * @dest: pointer of string
 * @src: pointer of string
 * Return: pointer of string
 */

char *_strcat(char *dest, char *src)
{

	int index_d;
	int index_s;

	for (index_d = 0; dest[index_d] != '\0'; index_d++)
	{
		continue;
	}

	for (index_s = 0; src[index_s] != '\0'; index_s++)
	{
		dest[index_d + index_s] = src[index_s];
	}

	dest[index_d + index_s + 1] = '\0';

	return (dest);

}


/**
 * _strcmp - cmpare two strings
 * @str1: string to compare
 * @str2: string to compare
 * Return: value str1 - str2
 */

int _strcmp(char *str1, char *str2)
{

	while (*str1 && *str2)
	{
		if (*str1 - *str2 != 0)
		{
			return (*str1 - *str2);
		}

		str1++;
		str2++;

	}

	return (0);

}

/**
 * _strdup - Duplicate a string
 * @str: The string to duplicate
 * Return: A pointer to the duplicated string
 */

char *_strdup(char *str)
{
	char *new_str;
	size_t len = _strlen(str);

	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
	{
		return (NULL);
	}

	_strcpy(new_str, str);

	return (new_str);

}
