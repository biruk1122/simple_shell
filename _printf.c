#include "main.h"
/**
 */
int _putchar(char c)
{
  return (write(1, &c, 1));
}
/**
 */
int _printf(const char *format, ...)
{
        va_list args;
        int i = 0, count = 0;
	char *str;

	va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 's')
            {
                str = va_arg(args, char *);

                while (*str != '\0')
                {
                    count += _putchar(*str);
                    str++;
                }
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return (count);
}
/**
 * err_msg - error message
 * @args: input string
 * @av: comand argument
 * @k: int value
 */
void err_msg(char *args, char *av, int k)
{
        int input = k;
        char val;

        _printf("%s: ", av);
        if (k < 10)
        {
                val = k + '0';
                _putchar(val);
        }
        else if (k > 9 && k < 100)
        {
                val = (k / 10) + '0';
        _putchar(val);
        val = (input % 10) + '0';
        _putchar(val);
    }
    _printf(": %s: not found\n", args);
}
/**
 */
void hash_tag(char *buffer)
{
        size_t j = 0;

        for (; buffer[j] != '\0'; j++) {
        if (buffer[j] == '#' && (j == 0 || buffer[j - 1] == ' '))
        {
            while (buffer[j] != '\0' && buffer[j] != '\n')
            {
                buffer[j] = ' ';
                j++;
            }
            if (buffer[j] == '\n')
            {
                j--;
            }
        }
    }
}
