Custom _printf Implementation
This project implements a simplified version of the C standard library function printf. It supports a limited set of format specifiers and demonstrates how to handle variadic arguments in C.

Overview
The _printf function is designed to print formatted output to the standard output (stdout). It supports the following format specifiers:

%c - Print a single character
%s - Print a string
%d - Print an integer (decimal notation)
%i - Print an integer (integer notation)
%% - Print a literal percent sign
Files
main.h - Header file containing function prototypes and the print_data struct definition.
print_functions.c - Contains implementations for the format specifier functions:
pr_char - Prints a single character.
pr_string - Prints a string, handling NULL strings by printing (null).
pr_int - Prints an integer.
_printf.c - Contains the implementation of the _printf function, which parses the format string and calls the appropriate print functions.
Usage
To use the custom _printf function, include the main.h header file and link the implementation files (print_functions.c and _printf.c) with your program.

Example
c
Copy code
#include "main.h"

int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Integer: %d\n", 123);
    _printf("Another Integer: %i\n", -456);
    _printf("Percent Sign: %%\n");

    return 0;
}
Compilation
Compile the project using gcc or another C compiler:

bash
Copy code
gcc -o my_printf main.c print_functions.c _printf.c
Replace main.c with your own source file that uses _printf.

Functions
_printf
c
Copy code
int _printf(const char *format, ...);
Parameters:

format: A format string containing format specifiers.
...: Additional arguments corresponding to the format specifiers.
Returns: The number of characters printed (excluding the null byte).

pr_char
c
Copy code
int pr_char(va_list char_list);
Parameters:

char_list: A va_list containing the character to print.
Returns: The number of characters printed (always 1).

pr_string
c
Copy code
int pr_string(va_list string_list);
Parameters:

string_list: A va_list containing the string to print.
Returns: The number of characters printed, including handling of NULL strings.

pr_int
c
Copy code
int pr_int(va_list int_list);
Parameters:

int_list: A va_list containing the integer to print.
Returns: The number of characters printed.

Limitations
This implementation does not handle:
Flag characters
Field width
Precision
Length modifiers
License
This project is licensed under the MIT License. See the LICENSE file for details.