#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

/**
 * pr_char - Prints a single character
 * @char_list: va_list containing the character to print
 *
 * Return: Number of characters printed
 */
int pr_char(va_list char_list)
{
    char letter = va_arg(char_list, int);
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
    int len = 0;
    char buffer[12];
    int i = 0, is_negative = 0;


    if (num < 0) {
        is_negative = 1;

        if (num == INT_MIN) {
            num = INT_MAX;
        } else {
            num = -num;
        }
    }


    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }


    if (is_negative) {

        if (num == INT_MAX) {
            buffer[0] = '8';
            buffer[i++] = '4';
            buffer[i++] = '6';
            buffer[i++] = '3';
            buffer[i++] = '7';
            buffer[i++] = '4';
            buffer[i++] = '8';
            buffer[i++] = '1';
            buffer[i++] = '2';
            buffer[i++] = '-';
        } else {
            buffer[i++] = '-';
        }
    }


    for (i--; i >= 0; i--) {
        _putchar(buffer[i]);
        len++;
    }

    return len;
}
