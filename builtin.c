#include "main.h"
int builtin_command(char *buffer, char **args, char **av)
{
        char **env = environ;
        int i = 0;
        size_t len;
        (void)av;

        if (args == NULL || args[0] == NULL)
        {
                free(buffer);
                return (0);
        }
    if (my_strcmp(args[0], "exit") == 0)
    {
        free(buffer);
        free_array_string(args);
        exit(0);
    }
    else if (my_strcmp(args[0], "env") == 0)
    {
            while (env[i] != NULL)
            {
                    len = _strlen(env[i]);
                    write(STDOUT_FILENO, env[i], len);
                    write(STDOUT_FILENO, "\n", 1);
                    i++;
            }
        return (1);
    }
    else if (my_strcmp(args[0], "cd") == 0)
        {
                if (args[1] == NULL)
                        chdir(customized_getenv("HOME"));
                else
                        chdir(args[1]);
                return (1);
        }
    return (0);
}
