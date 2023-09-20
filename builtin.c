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
    if (my_strstr(args[0], "exit")!= NULL)
    {
        free(buffer);
        free_array_string(args);
        exit(EXIT_SUCCESS);
    }
    else if (my_strstr(args[0], "env") != NULL)
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
    else if (my_strstr(args[0], "cd") != NULL)
        {
                if (args[1] == NULL)
                        chdir(customized_getenv("HOME"));
                else
                        chdir(args[1]);
                return (1);
        }
    return (0);
}
