#include "main.h"
/**
 * builtin_command - the builtin command
 * @buffer: buffer
 * @args: the arguments func
 * @av: argument vector
 * Return: Always return 1
 */
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
	else if (my_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] != NULL && args[2] != NULL)
		{
			if (_setenv(args[1], args[2], 1) != 0)
			{
				perror("setenv");
			}
		} else
		{
			_printf("Usage: setenv VARIABLE VALUE\n");
		}
		return (1);
	}
/*	else if (my_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] != NULL)
		{
			if (_unsetenv(args[1]) != 0)
			{
				perror("unsetenv");
			}
		} else
		{
			_printf("Usage: unsetenv VARIABLE\n");
		}
		return (1);
	}*/
	return (0);
}


/**
 * _setenv - the setenv cmd
 * @name: name of char
 * @value: the value
 * @overwrite: the overite
 * Return: the return value
 */
int _setenv(char *name, const char *value, int overwrite)
{
	size_t new_var_size = _strlen(name) + _strlen(value) + 2;
	char *new_env_var = (char *)malloc(new_var_size);
		int empty_slot = 0;
    if (name == NULL || name[0] == '\0' || my_strchr(name, '=') != NULL || value == NULL)
    {
	    return (-1);
    }
    if (new_env_var == NULL)
    {
	    return (-1);
    }
    _printf("%s=%s\n", name, value);
    while (environ[empty_slot] != NULL)
    {
	    empty_slot++;
    }
    environ[empty_slot] = new_env_var;
    free(new_env_var);
    return (0);
}
