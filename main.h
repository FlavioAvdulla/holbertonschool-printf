#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
typedef struct format_specifier
{
	char *specifier;
	int (*print_func)(va_list);
} format_specifier_t;


int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);


#endif
