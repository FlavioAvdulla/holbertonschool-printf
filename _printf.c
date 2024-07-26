#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

int handle_format(const char *format, va_list arg_list, int *i);
int print_char(char c);

/**
 * _printf - Custom printf function
 * @format: Format string containing the directives
 * @...: Additional arguments based on format specifiers
 *
 * Return: Number of characters printed or -1 if format is NULL
 */
int _printf(const char *format, ...)
{
    va_list arg_list;
    int i = 0, len = 0;

    va_start(arg_list, format);

    if (format == NULL)
        return (-1);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            len += handle_format(format, arg_list, &i);
        }
        else if (format[i] == '%' && format[i + 1] == '\0')
        {
            return (-1);
        }
        else
        {
            len += print_char(format[i]);
        }
        i++;
    }

    va_end(arg_list);
    return (len);
}

/**
 * handle_format - Handles format specifiers and prints the output
 * @format: Format string containing the directives
 * @arg_list: List of arguments
 * @i: Pointer to the current index in the format string
 *
 * Return: Number of characters printed for the format specifier
 */
int handle_format(const char *format, va_list arg_list, int *i)
{
    int j, len = 0;

    print_data p_func[] = {
        {"c", pr_char},
        {"s", pr_string},
        {"d", pr_int},
        {"i", pr_int},
        {NULL, NULL}
    };

    for (j = 0; p_func[j].type != NULL; j++)
    {
        if (format[*i + 1] == p_func[j].type[0])
        {
            len += p_func[j].print(arg_list);
            (*i)++;
            return (len);
        }
    }

    if (format[*i + 1] == '%')
    {
        len += print_char('%');
        (*i)++;
    }
    else
    {
        len += print_char('%');
        len += print_char(format[*i + 1]);
        (*i)++;
    }

    return (len);
}

/**
 * print_char - Prints a single character
 * @c: Character to print
 *
 * Return: Always 1 (number of characters printed)
 */
int print_char(char c)
{
    _putchar(c);
    return (1);
}
