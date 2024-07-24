#include "main.h"
#include <stdio.h>

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
	int num;

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
					c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
					case 'd':
					case 'i':
					num = va_arg(args, int);
					count += printf_number(num);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(format[i]);
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

	va_end(args);
	return (count);
}

/**
 * print_number - Prints an integer to stdout
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num = n;

	if (n < 0)
	{
		putchar('-');
		count++;
		num = -n;
	}

	if (num / 10)
	count += print_number(num / 10);

	putchar((num % 10) + '0');
	count++;

	return (count);
}
