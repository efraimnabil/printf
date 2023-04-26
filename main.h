#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_int(long int n, char c);
int print_pointer(void *p);
int handle_percent(const char *fmt, va_list ap);

#endif
