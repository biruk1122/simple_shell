#include "main.h"
void split_input(char **args, char *buffer, const char *delimiter)
{
    char *single_token, **token_array;
    int i = 0, j;


    token_array = (char **)malloc((ARGS_NO + 1) * sizeof(char *));
    if (token_array == NULL)
    {
        perror("Memory allocation for token_array failed");
        return;
    }

    single_token = strtok(buffer, delimiter);
    while (single_token != NULL && i < ARGS_NO - 1)
    {
        token_array[i] = _strdup(single_token);
        if (token_array[i] == NULL)
        {
            perror("Memory allocation for token failed");
            free_array_string(token_array);
            return;
        }
        single_token = strtok(NULL, delimiter);
        i++;
    }

    token_array[i] = NULL;


    for (j = 0; j <= i; j++)
    {
        args[j] = token_array[j];
    }


    free(token_array);
}

/**
 *
 */
int main(int ac, char **av, char **env)
{
    ssize_t  nread;
    size_t buffer_size = 0;
    char *buffer = NULL, *args[ARGS_NO], *get_path;
    const char *delm = " \t\n\r";
    int i = 0, b_status;
    int run = isatty(0);
    (void) ac;

    while (1)
    {
            if (run == 1)
                    printf("Bura_Ubutu$ ");
        nread = getline(&buffer, &buffer_size, stdin);
        if (nread == -1)
        {
                if (run == 1)
                        _printf("\n");
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        hash_tag(buffer);
        trim_newline(buffer);
        i++;
        split_input(args, buffer, delm);

        if (args[0] == NULL)
                continue;

       b_status = builtin_command(buffer, args, av);
       if (b_status != 0)
       {
              free_array_string(args);
               continue;
       }
       else
       {
               get_path = user_command(args[0]);
               if (get_path == NULL)
                {
                        err_msg(args[0], av[0], i);
                        free_array_string(args);
                        continue;
                }
               full_command(get_path, args, av, env);
       }

       free(get_path);
       free_array_string(args);
    }
    return (0);
}
