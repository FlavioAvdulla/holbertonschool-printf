	#include "main.h"
	#include <stdarg.h>
	#include <limits.h>

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
