#include "main.h"

/**
* _printf - Produces output according to a format
* @format: The format string
*
* Return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c;
	char *str;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(agrs, int);
					putchar(c);
					count++;
					break;
				case 's';
					str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					while (*str)
					{
						putchar (*str);
						str++;
						count++;
					}
					break;
				case '%':
					putchar ('%');
					count++;
					break;
				default:
					putchar ('%');
					putchar (format[i]);
					count += 2;
					break;

			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end (args);
	return (count);
}