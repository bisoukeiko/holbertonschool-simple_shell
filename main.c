#include "shell.h"

/**
 * main - Write 'function'
 * Return: always 0
 */

int main(void)
{
    char buffer[1024];
    char *command;
    char *args[2];

    while (1)
    {
        if (fgets(buffer, 1024, stdin) == NULL)
        {
            printf("\n");
            break;
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        if (buffer[0] == '\0')
            continue;

        command = buffer;
        args[0] = command;
        args[1] = NULL;

        execute(command, args);
    }

    return (0);
}

