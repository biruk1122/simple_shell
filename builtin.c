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
    else if (my_strcmp(args[0], "cd") == 0) {
            return (cd_builtin(args));
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
    else if (my_strcmp(args[0], "setenv") == 0) {
        if (args[1] != NULL && args[2] != NULL) {
            if (_setenv(args[1], args[2], 1) != 0) {
                perror("setenv");
            }
        } else {
            _printf("Usage: setenv VARIABLE VALUE\n");
        }
        return (1);
    }
    else if (my_strcmp(args[0], "unsetenv") == 0) {
        if (args[1] != NULL) {
            if (_unsetenv(args[1]) != 0) {
                perror("unsetenv");
            }
        } else {
            _printf("Usage: unsetenv VARIABLE\n");
        }
        return (1);
    }
    return (0);
}



int _setenv(char *name, const char *value, int overwrite)
{
	char **new_environ = NULL;
        int i, env_count = 0, new_var_size;

    if (name == NULL || name[0] == '\0' || my_strchr(name, '=') != NULL || value == NULL) {
        return (-1);
    }

    for (i = 0; environ[i] != NULL; i++) {
        if (my_strncmp(environ[i], name, _strlen(name)) == 0 && environ[i][_strlen(name)] == '=') {
            if (!overwrite) {
                return (0);
            }
            free(environ[i]);
        }
        free_array_string(environ);
    }

    while (environ[env_count] != NULL) {
        env_count++;
    }

    new_environ = (char **)malloc((env_count + 2) * sizeof(char *));
    if (new_environ == NULL) {
        return (-1);
    }

    for (i = 0; i < env_count; i++) {
        new_environ[i] = environ[i];
    }

    new_var_size = _strlen(name) + _strlen(value) + 2;

    new_environ[env_count] = (char *)malloc(new_var_size);
    if (new_environ[env_count] == NULL) {
        free_array_string(new_environ);
        return (-1);
    }
    free_array_string(environ);
    environ = new_environ;

    return (0);
}


int _unsetenv(char *name)
{
	char **new_environ = NULL;
        int i, new_env_count, env_count = 0;
	int found = 0;

    if (name == NULL || name[0] == '\0' || my_strchr(name, '=') != NULL) {
        return (-1);
    }

    while (environ[env_count] != NULL) {
        if (my_strncmp(environ[env_count], name, _strlen(name)) == 0 && environ[env_count][_strlen(name)] == '=') {
            found = 1;
            free(environ[env_count]);
        } else {
            env_count++;
        }
    }

    if (!found) {
        return (0);
    }
    new_env_count = 0;

    new_environ = (char **)malloc((env_count + 1) * sizeof(char *));
    if (new_environ == NULL) {
        return (-1);
    }
    for (i = 0; i < env_count; i++) {
        new_environ[i] = environ[i];
        new_env_count++;
    }

    new_environ[new_env_count] = NULL;

    free_array_string(environ);
    environ = new_environ;

    return (0);
}

int cd_builtin(char **args)
{
    char *home_dir, *old_dir, *new_dir, *current_dir;

    if (args[1] == NULL || my_strcmp(args[1], "~") == 0)
    {
        home_dir = customized_getenv("HOME");
        if (home_dir == NULL) {
            perror("cd");
            return (-1);
        }
        if (chdir(home_dir) != 0) {
            perror("cd");
        } else {
            _setenv("PWD", home_dir, 1);
        }
    } else if (my_strcmp(args[1], "-") == 0) {
        old_dir = customized_getenv("OLDPWD");
        if (old_dir == NULL) {
            perror("cd");
            return (-1);
        }
        if (chdir(old_dir) != 0) {
            perror("cd");
        } else {
            _setenv("PWD", old_dir, 1);
        }
    } else {
        new_dir = args[1];
        current_dir = getcwd(NULL, 0);
        if (current_dir == NULL) {
            perror("cd");
            return (-1);
        }
        if (chdir(new_dir) != 0) {
            perror("cd");
        } else {
            _setenv("PWD", current_dir, 1);
        }
        free(current_dir);
    }
    return (1);
}
