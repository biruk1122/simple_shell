#include <stddef.h>
#include "main.h"
/**
 * _strcpy - strcpy
 * @dest: dest
 * @src: src
 */
char *_strcpy(char *dest, const char *src)
{
    char *dst = dest;

    while ((*dest++ = *src++))
        ;
    return (dst);
}
/**
 * _srtdup - strdup
 * @s: s
 */

char *_strdup(const char *s)
{
    size_t len = 0;
    const char *src = s;
    char *copy;

    while (*src++)
        len++;
    copy = (char *)malloc(len + 1);

    if (copy != NULL)
    {
        _strcpy(copy, s);
    }
    return (copy);
}
/**
 * _strcat - strcat
 * @dest: dest
 * @src: src
 */
char *_strcat(char *dest, const char *src)
{
    char *dst = dest;

    while (*dest)
    {
        dest++;
    }
    while ((*dest++ = *src++))
	    ;
    return (dst);
}
/*
 * my_strcmp - srccmp
 * @s1: s1
 * @s2: s2
 */
int my_strcmp(const char *s1, const char *s2)
{

    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
