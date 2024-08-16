#include "shell.h"

/**
 * execute - Write
 * @command: c
 * @args: a
 */

void execute(char *command, char **args)
{
    pid_t pid = fork();
    int status;

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execve(command, args, NULL) == -1)
        {
            perror("./hsh");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(&status);
    }
}
