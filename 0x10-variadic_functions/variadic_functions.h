#ifndef VAR_FUNCTION_H
#define VAR_FUNCTION_H

#include <stdio.h>
#include <stdarg.h>

_putchar(char);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
