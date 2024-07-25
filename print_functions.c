	#include "main.h"
	#include <stdarg.h>
	#include <stdlib.h>
	#include <limits.h>

	/**
	* pr_char - Prints a single character.
	* @char_list: va_list containing the character to print.
	*
	* Return: Number of characters printed.
	*/
	int pr_char(va_list char_list)
	{
		char letter = va_arg(char_list, int);

		_putchar(letter);
		return (1);
	}

	/**
	* pr_string - Prints a string.
	* @string_list: va_list containing the string to print.
	*
	* Return: Number of characters printed.
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
	* pr_int - Prints an integer.
	* @int_list: va_list containing the integer to print.
	*
	* Return: Number of characters printed.
	*/
	int pr_int(va_list int_list)
	{
		int num = va_arg(int_list, int);
		int len = 0;

		if (num == 0)
		{
			handle_zero(&len);
		}
		else
		{
			if (num < 0)
			{
				print_negative(&len);
				num = -num;
			}
			handle_num(num, &len);
		}

		return (len);
	}

	/**
	* handle_num - Handles positive numbers and prints them.
	* @num: The number to print.
	* @len: Pointer to length of characters printed.
	*/
	void handle_num(int num, int *len)
	{
		if (num == 0)
		{
			_putchar('0');
			(*len)++;
			return;
		}

		if (num / 10)
			handle_num(num / 10, len);

		print_digit(num % 10, len);
	}

	/**
	* print_digit - Prints a single digit.
	* @num: The digit to print.
	* @len: Pointer to length of characters printed.
	*
	* Return: Number of characters printed.
	*/
	int print_digit(int num, int *len)
	{
		_putchar(num + '0');
		(*len)++;
		return (*len);
	}

	/**
	* print_negative - Prints a negative sign and handles INT_MIN.
	* @len: Pointer to length of characters printed.
	*/
	void print_negative(int *len)
	{
		_putchar('-');
		(*len)++;
	}

	/**
	* handle_zero - Prints zero.
	* @len: Pointer to length of characters printed.
	*/
	void handle_zero(int *len)
	{
		_putchar('0');
		(*len)++;
	}
