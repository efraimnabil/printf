#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_int(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int upper);
int print_binary(unsigned int n);
int print_pointer(void *p);
int just_print(char c);
int handle_percent(char *fmt, va_list ap);


#endif