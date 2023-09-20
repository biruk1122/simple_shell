#include "main.h"
/**
 * customized_getenv - the customized get env
 * @name: the char name
 * Return: the return value
 */
char *customized_getenv(const char *name)
{
	size_t len = _strlen(name);
	char **env = environ;
	size_t i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		char *equals_sign = my_strchr(env[i], '=');

		if (equals_sign != NULL)
		{
			size_t position = equals_sign - env[i];

			if (position == len && my_strncmp(env[i], name, len) == 0)
			{
				return (equals_sign + 1);
			}
		}
	}
	return (NULL);
}
/**
 * user_command - the user cmd
 * @args: the argument
 * Return: the return
 */
char *user_command(char *args)
{
	char *get_path, *fullPath = NULL, *copy_path, *tok;
	size_t arg_len, tok_len;
	int access_status = 1;

	if (args == NULL || my_strchr(args, '/') != NULL)

		return (_strdup(args));
	get_path = customized_getenv("PATH");
	if (get_path == NULL)
		return (NULL);
	copy_path = _strdup(get_path);
	if (copy_path == NULL)
		return (NULL);
	tok = strtok(copy_path, ":");
	while (tok != NULL)
	{
		tok_len = _strlen(tok);
		arg_len = _strlen(args);
		fullPath = (char *)malloc(tok_len + arg_len + 2);
		if (fullPath == NULL)
		{
			free(copy_path);
			return (NULL);
		}
		_strcpy(fullPath, tok);
		my_strcat(fullPath, "/");
		my_strcat(fullPath, args);
		access_status = access(fullPath, X_OK);
		if (access_status == 0)
		{
			free(copy_path);
			return (fullPath);
		}
		free(fullPath);
		tok = strtok(NULL, ":");
	}
	free(copy_path);
	return (NULL);
}
/**
 * full_command - the full cmd
 * @get_path: the get path func
 * @args: the argument
 * @av: arg vector
 * @env: the env
 * Return: the return
 */

int full_command(char *get_path, char **args, char **av, char **env)
{
	int waiting_status, command_status;

	pid_t child_pid;

	child_pid = fork();

	if (child_pid < 0)
	{
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		command_status = execve(get_path, args, env);
		if (command_status == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&waiting_status);
	return (0);
}
