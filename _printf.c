#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
* _printf - Custom printf function
* @format: Format string containing the directives
* @...: Additional arguments based on format specifiers
*
* Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
	va_list arg_list; // Declare a variable to hold the list of arguments
	int j, i = 0, len = 0; // Declare and initialize counters

	// Array of structures mapping format specifiers to their corresponding functions
	print_data p_func[] = {
		{"c", pr_char},
		{"s", pr_string},
		{"d", pr_int},
		{"i", pr_int},
		{NULL, NULL}
	};

	va_start(arg_list, format); // Initialize the argument list

	// Check if the format string is NULL
	if (format == NULL)
		return (0);
	// Iterate through each character in the format string
	while (format[i] != '\0') {
		if (format[i] == '%' && format[i+1] != '%') 
		{
			j = 0;
			// Search for the corresponding function for the format specifier
			while (p_func[j].type != NULL)
			{
				if (format[i+1] == p_func[j].type[0])
				{
					// Call the corresponding function and update the length
					len += p_func[j].print(arg_list);
					i++;
					break;
				}
				j++;
			}
			// If no matching function is found, print the '%' character
			if (p_func[j].type == NULL) {
				_putchar('%');
				len++;
			}
		}
		// Handle the case where '%%' is encountered, print a single '%'
		else if (format[i] == '%' && format[i+1] == '%')
		{
			_putchar('%');
			len++;
			i++;
		}
		// Handle regular characters, print them as is
		else 
		{
			_putchar(format[i]);
			len++;
		}
		i++;
	}

	va_end(arg_list); // Clean up the argument list
	return (len); // Return the total length of characters printed
}
