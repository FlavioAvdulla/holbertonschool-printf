# Custom _printf Implementation

This project implements a simplified version of the C standard library function **printf**. It supports a limited set of format specifiers and demonstrates how to handle variadic arguments in C.

## Overview

The **_printf** function is designed to print formatted output to the standard output **(stdout)**. It supports the following format specifiers:

**`%c`** - Print a single character

**`%s`** - Print a string

**`%d`** - Print an integer (decimal notation)

**`%i`** - Print an integer (integer notation)

**`%%`** - Print a literal percent sign

# Implementation Scheme

## Initialization
- _printf initializes a va_list to handle the variable arguments.

## Format String Parsing

The format string is traversed character by character.

## Format Specifier Handling

- When a % character is encountered, handle_format is called to determine and process the specifier.
- handle_format uses an array of structures (print_data) to map format specifiers to their corresponding functions.

## Printing

- Based on the specifier, the appropriate function (pr_char, pr_string, pr_int) is called to print the argument.
- print_char is used to print individual characters, including literal % characters.

## Return

The total number of characters printed is returned.

#
#

## Files

**1. main.h** - Header file containing function prototypes and the **print_data** struct definition.

**2. print_functions.c** - Contains implementations for the format specifier functions:

- **pr_char** - Prints a single character.
- **pr_string** - Prints a string, handling NULL strings by printing (null).
- **pr_int** - Prints an integer.

**3. _printf.c** - Contains the implementation of the **_printf** function, which parses the format string and calls the appropriate print functions.

## Usage

To use the custom _printf function, include the main.h header file and link the implementation files `(print_functions.c and _printf.c)` with your program.

## Example

```
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
```
## Compilation

Compile the project using gcc or another C compiler:

```
gcc -o my_printf main.c print_functions.c _printf.c
```
Replace **main.c** with your own source file that uses **_printf**.


## Functions

**_printf**

```
int _printf(const char *format, ...);
```
**Parameters**:

- **format:** A format string containing format specifiers.
- **...**: Additional arguments corresponding to the format specifiers.

**Returns**: The number of characters printed (excluding the null byte).

## pr_char
```
int pr_char(va_list char_list);
```
**Parameters:**

- char_list: A va_list containing the character to print.
- Returns: The number of characters printed (always **1**).

## pr_string

`int pr_string(va_list string_list);`

**Parameters**:

- string_list: A va_list containing the string to print.

- Returns: The number of characters printed, including handling of NULL strings.

## pr_int

```
int pr_int(va_list int_list);
```
**Parameters**:

- int_list: A va_list containing the integer to print.
- Returns: The number of characters printed.

## Limitations
This implementation does not handle:
- Flag characters
- Field width
- Precision
- Length modifiers

**_printf()** is written and maintained by **Stilian Saka** and **Flavio Avdulla**.