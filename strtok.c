#include "main.h"
/**
 * trim_newline - trim newline
 * @str: str
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
 *
 */
char *my_strtok(char *str, const char *delim)
{
    static char *last_token;
    char *token;

    if (str != NULL)
    {
        last_token = str;
    }
    else if (last_token == NULL)
    {
        return (NULL);
    }
    token = last_token;

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
