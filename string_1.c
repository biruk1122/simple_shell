#include "main.h"
/**
 * my_strcat - char strcat
 * @dest: dest
 * @src: src
 * Return: to return
 *
 */
char *my_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
/**
 * my_strncmp - the strncmp
 * @str1: str1
 * @str2: str2
 * @n: n
 * Return: to return
 */
int my_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (*str1 == '\0')
			return (0);
		++str1;
		++str2;
	}
	return (0);
}
/**
 * my_strchr - the str character
 * @str: str
 * @ch: ch
 * Return: to return
 */
char *my_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		++str;
	}
	return (NULL);
}
/**
 * _strlen - the strlen func
 * @str: the str
 * Return: to return
 */
size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * my_strstr - the str str
 * @haystack: the haystack char
 * @needle: the needle char
 * Return: the return func
 */
char *my_strstr(const char *haystack, const char *needle)
{
	size_t hay_len = _strlen(haystack);
	size_t needle_len = _strlen(needle);
	size_t i;
	size_t j = 0;

	if (needle_len == 0)
		return ((char *)haystack);
	for (i = 0; i < hay_len; i++)
	{
		if (hay_len - i < needle_len)
			break;

		while (j < needle_len && haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return ((char *)(haystack + i));
	}
	return (NULL);
}
