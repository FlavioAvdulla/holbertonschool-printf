	#include "main.h"
	#include <stdarg.h>
	#include <stdlib.h>

    // Forward declarations of helper functions
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
		va_list arg_list; // List to hold the variable arguments
		int i = 0, len = 0; // 'i' is the index for format string, 'len' is the length of printed characters

		va_start(arg_list, format); // Initialize the argument list

		if (format == NULL)
			return (-1); // Return -1 if format string is NULL

        // Loop through each character in the format string
		while (format[i] != '\0')
		{
			if (format[i] == '%' && format[i + 1] != '\0')
			{
                // Handle format specifier
				len += handle_format(format, arg_list, &i);
			}
			else if (format[i] == '%' && format[i + 1] == '\0')
			{
                // If '%' is the last character, return -1
				return (-1);
			}
			else
			{
                // Print regular character
				len += print_char(format[i]);
			}
			i++; // Move to the next character
		}

		va_end(arg_list); // Clean up the argument list
		return (len); // Return the total length of printed characters
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
        // Array of structures to map format specifiers to their corresponding functions
		print_data p_func[] = {
			{"c", pr_char},
			{"s", pr_string},
			{"d", pr_int},
			{"i", pr_int},
			{NULL, NULL}
		};
        // Loop through the mapping array to find the matching format specifier
		for (j = 0; p_func[j].type != NULL; j++)
		{
			if (format[*i + 1] == p_func[j].type[0])
			{
                // Call the appropriate function and update the length
				len += p_func[j].print(arg_list);
				(*i)++;
				return (len);
			}
		}
        // Handle "%%" which should print a single "%"
		if (format[*i + 1] == '%')
		{
			len += print_char('%');
			(*i)++; // Move index to skip the format specifier
		}
		else
		{
            // Handle unrecognized format specifier by printing it literally
			len += print_char('%');
			len += print_char(format[*i + 1]);
			(*i)++;
		}

		return (len); // Return the length of printed characters for the format specifier
	}

	/**
	* print_char - Prints a single character
	* @c: Character to print
	*
	* Return: Always 1 (number of characters printed)
	*/
	int print_char(char c)
	{
		_putchar(c); // Use _putchar function to print the character
		return (1); // Return 1 since one character is printed
	}
