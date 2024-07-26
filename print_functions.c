#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
 * pr_char - Prints a single character
 * @char_list: va_list containing the character to print
 *
 * Return: Number of characters printed
 */
int pr_char(va_list char_list)
{
    char letter = (char)va_arg(char_list, int);
    _putchar(letter);
    return (1);
}

/**
 * pr_string - Prints a string
 * @string_list: va_list containing the string to print
 *
 * Return: Number of characters printed
 */
int pr_string(va_list string_list)
{
    int i;
    char *word = va_arg(string_list, char*);

    if (word == NULL)
        word = "(null)";

    for (i = 0; word[i] != '\0'; i++)
        _putchar(word[i]);

    return (i);
}

/**
 * pr_int - Prints an integer
 * @int_list: va_list containing the integer to print
 *
 * Return: Number of characters printed
 */
int pr_int(va_list int_list)
{
    int num = va_arg(int_list, int);
    return pr_int_rec(num, 0);
}

/**
 * pr_int_rec - Recursively prints an integer
 * @n: The integer to print
 * @count: The count of characters printed so far
 *
 * Return: The updated count of characters printed
 */
int pr_int_rec(long int n, int count)
{
    if (n == INT_MIN) {
        _putchar('-');
        _putchar('2');
        n = 147483648; // INT_MIN without the leading '2'
        count += 2; // Account for '-' and '2'
    } else if (n < 0) {
        _putchar('-');
        n = -n;
        count++;
    }

    if (n / 10)
        count = pr_int_rec(n / 10, count + 1);

    _putchar(n % 10 + '0');
    count++;

    return count;
}
