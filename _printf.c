#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - Custom printf function
 * @format: Format string containing the directives
 * @...: Additional arguments based on format specifiers
 *
 * Return: Number of characters printed (excluding null byte) or -1 if format is NULL
 */
int _printf(const char *format, ...)
{
    va_list arg_list;
    int j, i = 0, len = 0;


    print_data p_func[] = {
        {"c", pr_char},
        {"s", pr_string},
        {"d", pr_int},
        {"i", pr_int},
        {NULL, NULL}
    };

    va_start(arg_list, format);


    if (format == NULL)
        return (-1);

    while (format[i] != '\0') {
        if (format[i] == '%' && format[i+1] != '\0' && format[i+1] != '%') 
        {
            j = 0;

            while (p_func[j].type != NULL)
            {
                if (format[i+1] == p_func[j].type[0])
                {
                    len += p_func[j].print(arg_list);
                    i++;
                    break;
                }
                j++;
            }

            if (p_func[j].type == NULL) {
                _putchar('%');
                len++;
            }
        }
        else if (format[i] == '%' && format[i+1] == '%')
        {
            _putchar('%');
            len++;
            i++;
        }
        else if (format[i] == '%' && format[i+1] == '\0')
        {
            return (-1);
        }
        else 
        {
            _putchar(format[i]);
            len++;
        }
        i++;
    }

    va_end(arg_list);
    return (len);    
}
