#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
* Return: number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	const char *p;

	va_start(args, format);
	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						write(1, &c, 1);
						printed_chars++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
						if (str == NULL)
							str = "(null)";
						while (*str)
						{
							write(1, str, 1);
							str++;
							printed_chars++;
						}
						break;
					}
				case '%':
					{
						char percent = '%';
						write(1, &percent, 1);
						printed_chars++;
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						char buffer[50];
						int len = snprintf(buffer, 50, "%d", num);
						write(1, buffer, len);
						printed_chars += len;
						break;
					}
				default:
					{
						write(1, p, 1);
						printed_chars++;
						break;
					}
			}
		}
		else
		{
			write(1, p, 1);
			printed_chars++;
		}
	}
	va_end(args);
	return printed_chars;
}