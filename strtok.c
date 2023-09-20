#include "main.h"
/**
 * trim_newline - the trim line
 * @str: str
 * Void: void func
 */
void trim_newline(char *str)
{
	size_t len = _strlen(str);

	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}
/**
 * my_strtok - strtok
 * @str: str
 * @delim: delim
 * Return: to return
 *
 */
char *my_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *token = last_token;

	if (str != NULL)
	{
		last_token = str;
	}
	else if (last_token == NULL)
	{
		return (NULL);
	}

	while (*last_token)
	{
		if (my_strchr(delim, *last_token))
		{
			*last_token = '\0';
			last_token++;
			break;
		}
		last_token++;
	}
	if (*token == '\0')
	{
		return (NULL);
	}
	else
	{
		return (token);
	}
}
