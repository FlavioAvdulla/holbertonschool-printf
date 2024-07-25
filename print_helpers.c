	#include "main.h"
	#include <stdarg.h>
	#include <limits.h>

	/**
	* handle_num - Recursively handles and prints positive integers.
	* @num: The number to print.
	* @len: Pointer to the length of characters printed.
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
	* print_digit - Prints a single digit of a number.
	* @num: The digit to print.
	* @len: Pointer to the length of characters printed.
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
	* @len: Pointer to the length of characters printed.
	*/
	void print_negative(int *len)
	{
		_putchar('-');
		(*len)++;
	}

	/**
	* handle_zero - Handles and prints the zero case.
	* @len: Pointer to the length of characters printed.
	*/
	void handle_zero(int *len)
	{
		_putchar('0');
		(*len)++;
	}
