#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>

#define ARGS_NO 100


extern char **environ;
/*strtok*/
char *my_strtok(char *str, const char *delim);
void trim_newline(char *str);

#define DELIMITER " \n\t"
/*free*/
void free_array_string(char **array);

/*customised printf and putchar*/
int _putchar(char c);
int _printf(const char *format, ...);
void err_msg(char *args, char *av, int k);
void hash_tag(char *buffer);

/*path case*/
char *customized_getenv(const char *name);
char *user_command(char *args);
int full_command(char *get_path, char **args, char **av, char **env);

/*builtin case*/
int builtin_command(char *buffer, char **args, char **av);
int _setenv(char *name, const char *value, int overwrite);
int _unsetenv(char *name);
int cd_builtin(char **args);

/*string_1*/
char *my_strcat(char *dest, const char *src);
char *my_strchr(const char *str, int ch);
size_t _strlen(const char *str);
char *my_strstr(const char *haystack, const char *needle);
int my_strncmp(const char *str1, const char *str2, size_t n);

/*string_2*/

char *_strcpy(char *dest, const char *src);
char *_strdup(const char *s);
char *_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);

#endif
