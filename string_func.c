#include "shell.h"

/**
 * _strlen - Return the length of a string
 * @str: string
 * Return: the length of a string
 */

int _strlen(char *str)
{
	int index = 0;

	while (*str)
	{
		index++;
		str++;
	}

	return (index);
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

